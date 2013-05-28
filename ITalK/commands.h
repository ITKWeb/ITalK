#ifndef COMMANDS_H
#define COMMANDS_H

#include <QString>
#include <QDate>
#include <QBool>

class Commands
{
private:
    QDate date;

    QString nom; // titre de la commande

    QString body; // commande en elle même, instruction, arguments

    QBool broadcast; // boolean si la command doit être envoyé à tous les users, sinon, liste de destinataire dans le body

public:
    Commands();

    void connect(); // broadcast

    void sendMessage(Message m);

    void createGroup(Group gp);

    void exitGroup(Group gp);

    void serialize();

    QString serialize();

    Commands deserialize(QString serialized);
};

#endif // COMMANDS_H
