#include "networkthread.h"

#include <QtNetwork>

#include "commands.h"

NetworkThread::NetworkThread(int socketDescriptor, QObject *parent) :
    QThread(parent), socketDescriptor(socketDescriptor), exit(false)
{
}

void NetworkThread::run()
{
    if (!tcpSocket.setSocketDescriptor(socketDescriptor)) {
        emit error(tcpSocket.error());
        return;
    }
    while(!exit) {
        if(tcpSocket.canReadLine()) {
            Commands::deserialize(tcpSocket.readLine());
        }
        sleep(1000);
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

    tcpSocket.write(block);
//    tcpSocket.disconnectFromHost();
//    tcpSocket.waitForDisconnected();
}
