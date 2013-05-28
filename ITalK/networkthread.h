#ifndef NETWORKTHREAD_H
#define NETWORKTHREAD_H

#include <QThread>
#include <QTcpSocket>

class NetworkThread : public QThread
{
    Q_OBJECT
public:
    explicit NetworkThread(int socketDescriptor, QObject *parent = 0);
    void run();
    void close();
    void send(QString command);
    
signals:
    void error(QTcpSocket::SocketError socketError);
    
public slots:

private:
    int socketDescriptor;
    QTcpSocket tcpSocket;
    bool exit;
    
};

#endif // NETWORKTHREAD_H
