#include "message.h"

#include <QStringList>

Message::Message(QString text, Group destinataires, User userFrom, QDate date) :
    text(text), destinataires(destinataires), userFrom(userFrom), date(date)
{
}

QString Message::serialize() {
    QStringList l =  QStringList();
    l << text;
    l << destinataires.serialize();
    l << userFrom.serialize();
    l << date.toString();
    return l.join("#");
}

Message Message::deserialize(QString serialized) {
    QStringList params = serialized.split("#");
    return Message(QString(params.at(0)), Group::deserialize(params.at(1)), User::deserialize(params.at(2)),
                   QDate::fromString(params.at(3)));
}
