#include "hometabwidget.h"
#include "ui_hometabwidget.h"

HomeTabWidget::HomeTabWidget(QWidget *parent) :
    QTabWidget(parent),
    ui(new Ui::HomeTabWidget)
{
    ui->setupUi(this);
}

HomeTabWidget::~HomeTabWidget()
{
    delete ui;
}
