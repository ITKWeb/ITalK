#include "user.h"

#include <QStringList>

User::User(QString nom, QString prenom, QString pole, QString description, QString image, QString ip, QString port) :
    nom(nom), prenom(prenom), pole(pole), description(description), image(image), ip(ip), port(port)
{
}

QString User::serialize() {
    QStringList l =  QStringList();
    l << nom;
    l << prenom;
    l << pole;
    l << description;
    l << image;
    l << ip;
    l << port;
    return l.join("#");
}

User User::deserialize(QString serialized) {
    QStringList params = serialized.split("#");
    return User(QString(params.at(0)), QString(params.at(1)), QString(params.at(2)), QString(params.at(3)), QString(params.at(4)),
                   QString(params.at(5)), QString(params.at(6)));
}
