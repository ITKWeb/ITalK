#include "italkmainwindow.h"
#include <QtGui>
#include <QIcon>
#include <QLabel>
#include <QImage>
#include <QPixmap>
#include <QCoreApplication>
#include <QObject>
#include <QPushButton>
#include "mainpage.h"
#include "discussion.h"
#include "group.h"
#include <QDebug>
#include "user.h"

iTalKMainWindow::iTalKMainWindow(QWidget *parent) :
    QDialog(parent)
{  
        italkWidgets= new QTabWidget;
        tabList = new QStringList();
        qDebug() << QCoreApplication::applicationDirPath();

        QIcon *icone = new QIcon(QCoreApplication::applicationDirPath() + "/../icones/home.png");
        MainPage *chooseGroup = new MainPage(this);
        italkWidgets->addTab(chooseGroup, *icone, tr("Groupes"));
        italkWidgets->setTabIcon(0, *icone);

        QObject::connect(chooseGroup, SIGNAL(startConversation(Group)), this, SLOT(startDiscussion(Group)));


        QVBoxLayout *mainLayout = new QVBoxLayout;
        mainLayout->addWidget(italkWidgets);
        setLayout(mainLayout);


        setWindowTitle(tr("iTalK"));

        moi = new User(tr("Pineau"), tr("Jef"), tr("info"), tr("dev"), tr(""), tr(""), tr(""));

 }



void iTalKMainWindow::startDiscussion(Group group) {

    Discussion *newDiscussion = new Discussion(*moi, group);
   int correspondingTab = italkWidgets->addTab(newDiscussion, group.getTitre());
   qDebug() << "new discussion linking group " << group.id << " to tab " << correspondingTab;
   tabList->append(group.id);
   QObject::connect(newDiscussion, SIGNAL(exit(QString)), this, SLOT(close(QString)));

}

void iTalKMainWindow::close(QString groupId) {
    //QObject * emetteur = sender();
    // On caste le sender en ce que nous supposons qu'il soit
    //Discussion * emetteurCasted = qobject_cast<Discussion*>(emetteur);
    //italkWidgets->removeTab(emetteurCasted->getCorrespondingTab());
    qDebug() << " Closing group " << groupId << " corresponding to tab list " << tabList->indexOf(groupId);

    italkWidgets->removeTab(tabList->indexOf(groupId)+1);
    tabList->removeOne(groupId); // group id unique
}

static QString appDirPath()
{
    #ifdef Q_WS_MAC
        return QCoreApplication::applicationDirPath().remove("/iTalK.app/Contents/MacOS"); // Va falloir adapter cette ligne
    #else
        return QCoreApplication::applicationDirPath();
    #endif
}
