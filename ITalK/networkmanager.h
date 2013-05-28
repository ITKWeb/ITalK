#ifndef NETWORKMANAGER_H
#define NETWORKMANAGER_H

#include <QTcpServer>
#include <QTcpSocket>

class NetworkManager : public QTcpServer
{
    Q_OBJECT
public:
    explicit NetworkManager(QObject *parent = 0);
    void sendMessage(QString content);
    
protected:
     void incomingConnection(int socketDescriptor);

signals:
    
public slots:
    
private:
     QList<int> ipAddressesList;
     QTcpSocket * serverSocket;

};

#endif // NETWORKMANAGER_H
