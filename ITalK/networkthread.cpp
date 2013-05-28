#include "networkthread.h"

#include <QtNetwork>

#include "commands.h"

NetworkThread::NetworkThread(int socketDescriptor, QObject *parent) :
    QThread(parent), exit(false)
{
}

NetworkThread::NetworkThread(QHostAddress sender, int port, QObject *parent) :
    QThread(parent), exit(false), sender(sender), port(port)
{
}

void NetworkThread::run()
{
    tcpSocket = new QTcpSocket();
    tcpSocket->connectToHost(sender, port);

    while(!exit) {
        if(tcpSocket->canReadLine()) {
            Commands cmd = Commands::deserialize(tcpSocket->readLine());
            qDebug() << "tcp receive " << cmd.serialize() << endl;
        }
        send("test");
        qDebug() << "send test" << endl;
        sleep(1);
    }
}

void NetworkThread::close()
{
    exit = true;
}

void NetworkThread::send(QString command)
{
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_0);
    out << (quint16)0;
    out << command;
    out.device()->seek(0);
    out << (quint16)(block.size() - sizeof(quint16));

    tcpSocket->write(block);
//    tcpSocket.disconnectFromHost();
//    tcpSocket.waitForDisconnected();
}
