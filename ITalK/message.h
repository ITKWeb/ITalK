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

    void serialize();

};

#endif // MESSAGE_H
