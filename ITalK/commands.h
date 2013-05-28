#ifndef COMMANDS_H
#define COMMANDS_H

class Commands
{
private:
    Date date;

    String nom; // titre de la commande

    String body; // commande en elle même, instruction, arguments

    boolean broadcast; // boolean si la command doit être envoyé à tous les users, sinon, liste de destinataire dans le body

public:
    Commands();

    serialize();
};

#endif // COMMANDS_H
