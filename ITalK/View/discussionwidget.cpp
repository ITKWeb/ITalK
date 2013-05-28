#include "discussionwidget.h"
#include "ui_discussionwidget.h"

DiscussionWidget::DiscussionWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DiscussionWidget)
{
    ui->setupUi(this);
}

DiscussionWidget::~DiscussionWidget()
{
    delete ui;
}
