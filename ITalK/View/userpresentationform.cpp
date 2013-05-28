#include "userpresentationform.h"
#include "ui_userpresentationform.h"
#include <QList>
#include "user.h"
#include "group.h"

UserPresentationForm::UserPresentationForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserPresentationForm)
{
    ui->setupUi(this);

    // TEST
        QList<User> users;
        User moi(tr("Pineau"), tr("Jef"), tr("info"), tr("dev"), tr(""), tr(""), tr(""));
        users.append(moi);
        Group group(tr("1"), tr("Groupe Moi"), users);
    //test
        ui->fullName->setText(moi.nom);

}

UserPresentationForm::~UserPresentationForm()
{
    delete ui;
}
