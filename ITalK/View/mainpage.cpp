#include "mainpage.h"
#include <QLabel>
#include <QListWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QDebug>
#include <QStringList>
#include <QVBoxLayout>
#include <QPushButton>
#include "userpresentationform.h"

MainPage::MainPage(QWidget *p) :
    QWidget(p)
{
    //QLabel *fileNameLabel = new QLabel(tr("File Name:"));
    parent = p;
    //QLineEdit *fileNameEdit = new QLineEdit("My name");

    //QLabel *pathValueLabel = new QLabel(tr("Another label"));
    //pathValueLabel->setFrameStyle(QFrame::Panel | QFrame::Sunken);

    //QCheckBox *readable = new QCheckBox(tr("Readable"));

    QListWidget *userListBox = new QListWidget;
         //UserPresentationForm user();
    QStringList applications;
    UserPresentationForm *form = new UserPresentationForm();



    applications.append(tr("Jef Pineau"));
    applications.append(tr("Romain Maneschi"));

    userListBox->insertItems(0, applications);

    QLabel *image = new QLabel();
    image->setPixmap(QPixmap(":/home.png"));

    QPushButton *discussion = new QPushButton();
    discussion->setText(tr("Commencer la discussion"));
    QObject::connect(discussion, SIGNAL(clicked()), this, SLOT(sendConversationSignal()));


    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(image);
    mainLayout->addWidget(userListBox);
    mainLayout->addWidget(form);
    mainLayout->addWidget(discussion);
    setLayout(mainLayout);

}

int i=1;
void MainPage::sendConversationSignal() {
    // TEST
    qDebug() << "start Conversation clicked";

        QList<User> users;
        for (int j=0; j<i;j++) {
            User moi(tr("Pineau %1").arg(j), tr("Jef"), tr("info"), tr("dev"), tr(""), tr(""), tr(""));
            users.append(moi);
        }
     Group group(tr("%1").arg(i), tr("Groupe Moi %1").arg(i), users);
     i++;
    //test
    emit startConversation(group);
    //parent->startDiscussion();
}
