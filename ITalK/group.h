#ifndef GROUP_H
#define GROUP_H

#include "user.h"

#include <QString>
#include <QList>

class Group
{
private:
    QString id; // unique identifiant

    QString titre; // optionel, nom du group pour le retrouver sur la page de sélection

    QList<User> users; // ensemble des personnes du groupe

public:
    Group(QString id, QString titre, QList<User> users);

    QString getId();

    QString getTitre();

    QString serialize();

    static Group deserialize(QString serialized);
};

#endif // GROUP_H
