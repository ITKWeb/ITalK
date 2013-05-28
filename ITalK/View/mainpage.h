#ifndef MAINPAGE_H
#define MAINPAGE_H

#include <QWidget>
#include "group.h"

class MainPage : public QWidget
{
    Q_OBJECT

private:
    QWidget *parent;

public:
    explicit MainPage(QWidget *parent = 0);

signals:
    void startConversation(Group gp);
    
public slots:
    void sendConversationSignal();
    
};

#endif // MAINPAGE_H
