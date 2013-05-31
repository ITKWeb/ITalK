#ifndef MESSAGE_H
#define MESSAGE_H

#include "user.h"
#include "group.h"

#include <QString>
#include <QDate>

class Message
{
public:
    QString text;

    Group destinataires;

    User userFrom;

    QDate date;

    Message(QString text, Group destinataires, User userFrom, QDate date);

    QString serialize();

    static Message deserialize(QString serialized);

};

#endif // MESSAGE_H
