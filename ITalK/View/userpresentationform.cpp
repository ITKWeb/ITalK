#include "userpresentationform.h"
#include "ui_userpresentationform.h"

UserPresentationForm::UserPresentationForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserPresentationForm)
{
    ui->setupUi(this);
}

UserPresentationForm::~UserPresentationForm()
{
    delete ui;
}
