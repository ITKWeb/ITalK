#include "commands.h"

Commands::Commands() : date(QDate()), nom(""), body(""), broadcast(true)
{
}

QString Commands::serialize() {
    return QString();
}

Commands Commands::deserialize(QString serialized) {
    return Commands();
}
