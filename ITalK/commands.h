#ifndef COMMANDS_H
#define COMMANDS_H

#include <QString>
#include <QDate>
#include <QBool>

#include "message.h"

class Commands
{
private:
    QDate date;

    QString nom; // titre de la commande

    QString body; // commande en elle même, instruction, arguments

    QBool broadcast; // boolean si la command doit être envoyé à tous les users, sinon, liste de destinataire dans le body

public:
    Commands(QDate date, QString nom, QString body, bool broadcast);

    QString serialize();

    static Commands deserialize(QString serialized);

    static Commands buildConnect();

    static Commands buildMessage(Message message);
};

#endif // COMMANDS_H
