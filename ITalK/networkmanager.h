#ifndef NETWORKMANAGER_H
#define NETWORKMANAGER_H

#include "commands.h"

#include <QTcpServer>
#include <QTcpSocket>
#include <QUdpSocket>

class NetworkManager : public QTcpServer
{
    Q_OBJECT
public:
    explicit NetworkManager(int port, QObject *parent = 0);
    void sendCommand(Commands command);
    
protected:
     void incomingConnection(int socketDescriptor);
     void brodcastMessage(QString content);
     void startDiscussion(QHostAddress sender);

signals:
    
public slots:
     void socketChange(QAbstractSocket::SocketState socket);
     void newClient();
    
private:
     int port;
     QList<int> ipAddressesList;
     QTcpSocket * serverSocket;
     QUdpSocket * broadcastSocket;

};

#endif // NETWORKMANAGER_H
