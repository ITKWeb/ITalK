#include "mainpage.h"

MainPage::MainPage(QWidget *parent) :
    QWidget(parent)
{
    QLabel *fileNameLabel = new QLabel(tr("File Name:"));

    QLineEdit *fileNameEdit = new QLineEdit(fileInfo.fileName());

    QLabel *pathValueLabel = new QLabel(fileInfo.absoluteFilePath());
    pathValueLabel->setFrameStyle(QFrame::Panel | QFrame::Sunken);

    QCheckBox *readable = new QCheckBox(tr("Readable"));

    QListWidget *applicationsListBox = new QListWidget;
    QStringList applications;

    for (int i = 1; i <= 30; ++i)
        applications.append(tr("Application %1").arg(i));
    applicationsListBox->insertItems(0, applications);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(fileNameLabel);
    mainLayout->addWidget(fileNameEdit);
    mainLayout->addWidget(pathValueLabel);
    mainLayout->addWidget(readable);
    mainLayout->addWidget(applicationsListBox);
    setLayout(mainLayout);

}
