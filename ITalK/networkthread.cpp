#include "networkthread.h"

NetworkThread::NetworkThread(int socketDescriptor, QObject *parent) :
    QThread(parent), exit(false), socketDescriptor(socketDescriptor), connectWithIp(false)
{
}

NetworkThread::NetworkThread(QHostAddress sender, int port, QObject *parent) :
    QThread(parent), exit(false), sender(sender), port(port), connectWithIp(true)
{
}

void NetworkThread::run()
{
    blockSize = 0;
    tcpSocket = new QTcpSocket();
    connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(read()));
    if(connectWithIp) {
        qDebug() << "TCP connect to " << sender << "::" << port << endl;
        tcpSocket->connectToHost(sender, port);
    } else {
        qDebug() << "TCP connect with " << socketDescriptor << endl;
        tcpSocket->setSocketDescriptor(socketDescriptor);
    }
    if(!tcpSocket->waitForConnected(1000)) {
        qDebug() << "socket no connect" << tcpSocket->errorString() << endl;
    } else {
        qDebug() << "socket really connected" << endl;
    }

    send(Commands::buildConnect());
    qDebug() << "send " << Commands::buildConnect().serialize() << endl;

    exec();
}


void NetworkThread::read()
{
    qDebug() << "tcp received nb data " << tcpSocket->bytesAvailable() << endl;

    QDataStream in(tcpSocket);
    in.setVersion(QDataStream::Qt_4_0);

    if (blockSize == 0) {
        if (tcpSocket->bytesAvailable() < (int)sizeof(quint16))
        {
            qDebug() << "not data " << tcpSocket->bytesAvailable() << endl;
            return;
        }

        in >> blockSize;
        qDebug() << "block size " << blockSize << endl;
    }

    if (tcpSocket->bytesAvailable() < blockSize)
    {
        qDebug() << "not data 2 " << tcpSocket->bytesAvailable() << endl;
        return;
    }

    QString serializedCmd;
    in >> serializedCmd;

    qDebug() << "tcp received " << QString(serializedCmd) << endl;

}

void NetworkThread::close()
{
    exit = true;
}

void NetworkThread::send(Commands cmd)
{
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_0);
    out << (quint16)0;
    out << cmd.serialize();
    out.device()->seek(0);
    out << (quint16)(block.size() - sizeof(quint16));

    tcpSocket->write(block);
    tcpSocket->flush();
    tcpSocket->waitForBytesWritten();
//    tcpSocket.disconnectFromHost();
//    tcpSocket.waitForDisconnected();
}
