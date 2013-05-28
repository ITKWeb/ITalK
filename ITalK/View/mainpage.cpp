#include "mainpage.h"
#include <QLabel>
#include <QListWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QStringList>
#include <QVBoxLayout>
#include <QPushButton>
#include "userpresentationform.h"

MainPage::MainPage(QWidget *parent) :
    QWidget(parent)
{
    //QLabel *fileNameLabel = new QLabel(tr("File Name:"));

    //QLineEdit *fileNameEdit = new QLineEdit("My name");

    //QLabel *pathValueLabel = new QLabel(tr("Another label"));
    //pathValueLabel->setFrameStyle(QFrame::Panel | QFrame::Sunken);

    //QCheckBox *readable = new QCheckBox(tr("Readable"));

    QListWidget *userListBox = new QListWidget;
         //UserPresentationForm user();
    QStringList applications;
    UserPresentationForm *form = new UserPresentationForm();


    for (int i = 1; i <= 10; ++i)
        applications.append(tr("User%1").arg(i));
    userListBox->insertItems(0, applications);

    QLabel *image = new QLabel();
    image->setPixmap(QPixmap(":/home.png"));

    QPushButton *discussion = new QPushButton();
    discussion->setText(tr("Commencer la discussion"));
    QObject::connect(discussion, SIGNAL(clicked()), this, SLOT(sendConversationSignal()));
    QObject::connect(this, SIGNAL(startConversation(Group)), parent, SLOT(iTalKMainWindow::startDiscussion()));


    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(image);
    mainLayout->addWidget(userListBox);
    mainLayout->addWidget(form);
    mainLayout->addWidget(discussion);
    setLayout(mainLayout);

}

void MainPage::sendConversationSignal() {
    // TEST
        QList<User> users;
      User moi(tr("Pineau"), tr("Jef"), tr("info"), tr("dev"), tr(""), tr(""), tr(""));
     users.append(moi);
     Group group(tr("1"), tr("Groupe Moi"), users);
    //test
    emit startConversation(group);
}
