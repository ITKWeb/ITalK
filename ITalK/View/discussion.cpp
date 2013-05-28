#include "discussion.h"
#include "ui_discussion.h"

Discussion::Discussion(Group &group, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Discussion)
{
    ui->setupUi(this);

   connect(ui->exitGroupButton, SIGNAL(clicked()), this, SLOT(afficherMessageQuitter));
   ui->textBrowser->insertPlainText(tr("Quitter le groupe"));
}

Discussion::~Discussion()
{
    delete ui;
}

void afficherMessageQuitter() {
}
