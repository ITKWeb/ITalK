#include "commands.h"

#include <QStringList>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <QDebug>
#include "message.h"

Commands::Commands(QDate date, QString nom, QString body, bool broadcast) : date(date), nom(nom), body(body), broadcast(broadcast)
{
}

QString Commands::serialize() {
    QString b = "0";
    if(broadcast) {
        b = "1";
    }
    QStringList l =  QStringList();
    l << date.toString();
    l << nom;
    l << body;
    l << b;
    return l.join("#");
}

Commands Commands::deserialize(QString serialized) {
    QStringList params = serialized.split("#");
    bool b = false;
    if(QString(params.at(3)) == "1") {
        b = true;
    }
    return Commands(QDate::fromString(params.at(0)), QString(params.at(1)), QString(params.at(2)), b);
}

Commands Commands::buildConnect() {
    QFile file("../ITalK/config.txt");
    if(!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0, "error", file.errorString());
    }

    QTextStream in(&file);
    QString line = in.readLine();
    qDebug() << "LINE TEXT == " << line << endl;
    User user = User::deserialize(line);

    file.close();
    return Commands(QDate(), QString("connect"), user.serialize(), true);
}

Commands Commands::buildMessage(Message message) {
    return Commands(QDate(), QString("msg"), message.serialize(), false);
}
