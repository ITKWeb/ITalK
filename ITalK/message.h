#ifndef MESSAGE_H
#define MESSAGE_H

#include "user.h"
#include "group.h"

#include <QString>
#include <QDate>

class Message
{
private:
    QString text;

    Group destinataires;

    User userFrom;

    QDate date;

public:
    Message(QString text, Group destinataires, User userFrom, QDate date);

    QString serialize();

    static Message deserialize(QString serialized);

};

#endif // MESSAGE_H
