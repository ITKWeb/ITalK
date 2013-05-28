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

    Message(Group dest, String text, User from, Date date);

    void serialize();

    Date getDate();

    User getUserFrom();

    Group getDestinataires();

    String getText();

};

#endif // MESSAGE_H
