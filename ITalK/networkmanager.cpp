#include "networkmanager.h"

#include "networkthread.h"

NetworkManager::NetworkManager(int port, QObject *parent) :
    QTcpServer(parent), port(port)
{
    listen(QHostAddress::Any, port);
    qDebug() << "server listen on 5858";
    //sendMessage(QString("hello world !"));
    broadcastSocket = new QUdpSocket(this);
    broadcastSocket->bind(QHostAddress::Any, port);
    connect(broadcastSocket, SIGNAL(readyRead()),
                 this, SLOT(newClient()));
    brodcastMessage(QString("hello !"));
}

void NetworkManager::newClient()
{
    while (broadcastSocket->hasPendingDatagrams()) {
        QByteArray datagram;
        datagram.resize(broadcastSocket->pendingDatagramSize());
        broadcastSocket->readDatagram(datagram.data(), datagram.size());
        qDebug() << "broadcast receive " << datagram.data() << endl;
    }
}

void NetworkManager::incomingConnection(int socketDescriptor)
{
    NetworkThread * thread = new NetworkThread(socketDescriptor, this);
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
    qDebug() << "new connection on 5858" << endl;
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
