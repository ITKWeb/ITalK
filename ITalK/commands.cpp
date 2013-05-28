#include "commands.h"

Commands::Commands(QDate date, QString nom, QString body, bool broadcast) : date(date), nom(nom), body(body), broadcast(broadcast)
{
}

QString Commands::serialize() {
    return QString("");
}

Commands Commands::deserialize(QString serialized) {
    return Commands(QDate(), QString("nom"), QString("body"), false);
}
