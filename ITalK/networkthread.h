#ifndef NETWORKTHREAD_H
#define NETWORKTHREAD_H

#include <QThread>
#include <QTcpSocket>
#include <QHostAddress>

class NetworkThread : public QThread
{
    Q_OBJECT
public:
    NetworkThread(int socketDescriptor, QObject *parent = 0);
    NetworkThread(QHostAddress sender, int port = 0, QObject *parent=0);
    void run();
    void close();
    void send(QString command);
    
signals:
    void error(QTcpSocket::SocketError socketError);
    
public slots:

private:
    QTcpSocket * tcpSocket;
    bool exit;
    QHostAddress sender;
    int port;
    
};

#endif // NETWORKTHREAD_H
