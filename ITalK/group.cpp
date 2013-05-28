#include "group.h"

#include <QStringList>

Group::Group(QString id, QString titre, QList<User> users) : id(id), titre(titre), users(users)
{
}

QString Group::getId() {
    return id;
}

QString Group::getTitre() {
    if (titre == NULL) {
        return "";
    } else {
        return titre;
    }
}

QString Group::serialize() {
    QStringList l =  QStringList();
    l << id;
    l << titre;
    return l.join("#");
}

Group Group::deserialize(QString serialized) {
    QStringList params = serialized.split("#");
    return Group(QString(params.at(0)), QString(params.at(1)), QList<User>());
}
