#include "discussion.h"
#include "ui_discussion.h"
#include "message.h"
#include <QDebug>
#include <QObject>

Discussion::Discussion(User me, Group group, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Discussion),
    moi(me),
    currentDiscussion(group)
{
    ui->setupUi(this);

    QList<User> users = group.users;
    for (int i=0; i<users.size();i++) {
        ui->GroupList->insertPlainText(tr("%1 %2\n").arg(users.at(i).prenom, users.at(i).nom));
    }


    //QObject::connect(ui->exitGroupButton, SIGNAL(clicked()), this, SLOT(on_exitGroupButton_clicked()));
    QObject::connect(ui->sendButton, SIGNAL(clicked()), this, SLOT(envoyerMessage()));
    QObject::connect(ui->textEdit, SIGNAL(returnPressed()), this, SLOT(envoyerMessage()));

}

Discussion::~Discussion()
{
    delete ui;
}

void Discussion::on_exitGroupButton_clicked() {
    ui->textBrowser->insertPlainText(tr("Quitter le groupe \n"));
    qDebug() << "exit clicked";
    emit exit(currentDiscussion.id);
}

void Discussion::envoyerMessage() {
    QString text = ui->textEdit->text()+"\n";
    QDate now;
    Message aEnvoyer(text, currentDiscussion, moi, now);
    // Command envoyer
    afficherMessage(aEnvoyer);
    ui->textEdit->setText(tr(""));
    qDebug() << "send clicked";
}

void Discussion::afficherMessage(Message message) {
    ui->textBrowser->insertPlainText(message.date.toString());
    // m_quitter->setFont(QFont("Comic Sans MS", 14));
    ui->textBrowser->insertPlainText(tr(" "));
    ui->textBrowser->insertPlainText(message.userFrom.nom);
    ui->textBrowser->insertPlainText(tr(": "));
    ui->textBrowser->insertPlainText(message.text);
}

