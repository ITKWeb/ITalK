#include "networkmanager.h"

#include "networkthread.h"

NetworkManager::NetworkManager(int port, QObject *parent) :
    QTcpServer(parent), port(port)
{
    listen(QHostAddress::Any, port);
    qDebug() << "server listen on " << port << endl;
    broadcastSocket = new QUdpSocket(this);
    connect(broadcastSocket, SIGNAL(readyRead()), this, SLOT(newClient()));
    broadcastSocket->bind(QHostAddress::Any, port);
    brodcastMessage(QString("hello !"));
}

void NetworkManager::newClient()
{
    while (broadcastSocket->hasPendingDatagrams()) {
        QByteArray datagram;
        datagram.resize(broadcastSocket->pendingDatagramSize());
        QHostAddress sender;
        quint16 senderPort;
        broadcastSocket->readDatagram(datagram.data(), datagram.size(), &sender, &senderPort);
        qDebug() << "broadcast receive " << QString(datagram.data()) << sender << senderPort << endl;
        startDiscussion(sender);
    }
}

void NetworkManager::startDiscussion(QHostAddress sender)
{
    NetworkThread * thread = new NetworkThread(sender, port);
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
    qDebug() << "start discussion on " << port << endl;
    thread->start();
}

void NetworkManager::incomingConnection(int socketDescriptor)
{
    NetworkThread * thread = new NetworkThread(socketDescriptor);
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
    qDebug() << "new connection on " << port << endl;
    thread->start();
}

void NetworkManager::sendCommand(Commands command)
{
//    serverSocket = new QTcpSocket(this);
//    serverSocket->setSocketOption(QAbstractSocket::MulticastTtlOption, QVariant(1));
//    connect(serverSocket, SIGNAL(stateChanged(QAbstractSocket::SocketState)), this, SLOT(socketChange(QAbstractSocket::SocketState)));
//    serverSocket->connect()
    QByteArray datagram;
    QDataStream out(&datagram, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_1);
    QString serializedCmd = command.serialize();
    out << serializedCmd;
    out.setDevice(serverSocket);
    qDebug() << "send " << serializedCmd << endl;
    serverSocket->write(datagram);
    serverSocket->flush();
}

void NetworkManager::brodcastMessage(QString content)
{
    QByteArray datagram;
    QDataStream out(&datagram, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_1);
    out << content;
    out.setDevice(broadcastSocket);
    qDebug() << "broadcast send " << content << endl;
    broadcastSocket->writeDatagram(datagram.data(), datagram.size(), QHostAddress::Broadcast, port);
}

void NetworkManager::socketChange(QAbstractSocket::SocketState socket)
{
    qDebug() << socket << endl;
}
