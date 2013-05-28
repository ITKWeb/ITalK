#include "mainpage.h"
#include <QLabel>
#include <QListWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QStringList>
#include <QVBoxLayout>

MainPage::MainPage(QWidget *parent) :
    QWidget(parent)
{
    QLabel *fileNameLabel = new QLabel(tr("File Name:"));

    QLineEdit *fileNameEdit = new QLineEdit("My name");

    QLabel *pathValueLabel = new QLabel(tr("Another label"));
    pathValueLabel->setFrameStyle(QFrame::Panel | QFrame::Sunken);

    QCheckBox *readable = new QCheckBox(tr("Readable"));

    QListWidget *applicationsListBox = new QListWidget;
    QStringList applications;

    for (int i = 1; i <= 30; ++i)
        applications.append(tr("Application %1").arg(i));
    applicationsListBox->insertItems(0, applications);

    QLabel *image = new QLabel();
    image->setPixmap(QPixmap("home.png"));

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(image);
    mainLayout->addWidget(fileNameLabel);
    mainLayout->addWidget(fileNameEdit);
    mainLayout->addWidget(pathValueLabel);
    mainLayout->addWidget(readable);
    mainLayout->addWidget(applicationsListBox);
    setLayout(mainLayout);

}
