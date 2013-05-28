#include "networkmanager.h"

#include "networkthread.h"

NetworkManager::NetworkManager(QObject *parent) :
    QTcpServer(parent)
{
    listen(QHostAddress::Any, 5858);
}

void NetworkManager::incomingConnection(int socketDescriptor)
{
    NetworkThread * thread = new NetworkThread(socketDescriptor, this);
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
    thread->start();
}

void NetworkManager::sendMessage(QString content)
{
    serverSocket = nextPendingConnection();
    QByteArray datagram;
    QDataStream out(&datagram, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_1);
    out << content;
    out.setDevice(serverSocket);
    //tcpSocket->writeDatagram(datagram, QHostAddress::LocalHost, 5824);
    serverSocket->write(datagram);
    serverSocket->flush();
}
