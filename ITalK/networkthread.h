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
    
signals:
    void error(QTcpSocket::SocketError socketError);
    
public slots:

private:
    int socketDescriptor;
    
};

#endif // NETWORKTHREAD_H
