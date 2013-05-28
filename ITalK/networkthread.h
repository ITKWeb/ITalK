#ifndef NETWORKTHREAD_H
#define NETWORKTHREAD_H

#include <QThread>
#include <QTcpSocket>
#include <QHostAddress>

#include "commands.h"

class NetworkThread : public QThread
{
    Q_OBJECT
public:
    NetworkThread(int socketDescriptor, QObject *parent = 0);
    NetworkThread(QHostAddress sender, int port = 0, QObject *parent=0);
    void run();
    void close();
    void send(Commands cmd);
    
signals:
    void error(QTcpSocket::SocketError socketError);
    
public slots:
    void read();

private:
    QTcpSocket * tcpSocket;
    bool exit;
    QHostAddress sender;
    int port;
    int socketDescriptor;
    bool connectWithIp;
    quint16 blockSize;
    
};

#endif // NETWORKTHREAD_H
