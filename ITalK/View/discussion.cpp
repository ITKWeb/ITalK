#include "discussion.h"
#include "ui_discussion.h"
#include <QDebug>
#include <QObject>

Discussion::Discussion(Group &group, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Discussion)
{
    ui->setupUi(this);

    QList<User> users = group.users;
    for (int i=0; i<users.size();i++) {
        ui->GroupList->insertPlainText(tr("%1 %2\n").arg(users.at(i).prenom, users.at(i).nom));
    }


    //QObject::connect(ui->exitGroupButton, SIGNAL(clicked()), this, SLOT(on_exitGroupButton_clicked()));
    QObject::connect(ui->sendButton, SIGNAL(clicked()), this, SLOT(afficherMessage()));
}

Discussion::~Discussion()
{
    delete ui;
}
int i=1;
void Discussion::on_exitGroupButton_clicked() {
    ui->textBrowser->insertPlainText(tr("Quitter le groupe \n"));
    qDebug() << "exit clicked";
    emit exit();
}

void Discussion::afficherMessage() {
    ui->textBrowser->insertPlainText(ui->textEdit->text());
    ui->textBrowser->insertPlainText(tr("\n"));
    ui->textEdit->setText(tr(""));
    qDebug() << "send clicked";
}


void Discussion::setCorrespondingTab(int id) {
    tabId = id;
}

int Discussion::getCorrespondingTab() {
    return tabId;
}
