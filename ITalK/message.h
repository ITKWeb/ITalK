#ifndef MESSAGE_H
#define MESSAGE_H

#include "user.h"
#include "group.h"

#include <QString>

class Message
{
private:
    QString text;

    Group destinataires;

    User userFrom;

    QString dateTime;

public:
    Message();

    Message(Group dest, QString text, User from, QString date);

    void serialize();

    QString getDate();

    User getUserFrom();

    Group getDestinataires();

    QString getText();

};

#endif // MESSAGE_H
