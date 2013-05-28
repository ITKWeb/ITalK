#include "italkmainwindow.h"
#include <QtGui>
#include <QIcon>
#include <QLabel>
#include <QImage>
#include <QPixmap>
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
        QIcon *icone = new QIcon(":/home.png");
        italkWidgets->addTab(new MainPage(), *icone, tr("Groupes"));
        italkWidgets->setTabIcon(0, *icone);



        QVBoxLayout *mainLayout = new QVBoxLayout;
        mainLayout->addWidget(italkWidgets);
        setLayout(mainLayout);


        setWindowTitle(tr("iTalK"));
 }


int j=1;

void iTalKMainWindow::startDiscussion() {

    // TEST
        QList<User> users;
        User moi(tr("Pineau"), tr("Jef"), tr("info"), tr("dev"), tr(""), tr(""), tr(""));
        users.append(moi);
        Group group(tr("1"), tr("Discussion %1").arg(j), users);
        j++;
    //test
   italkWidgets->addTab(new Discussion(group), group.getTitre());
   show();
   qDebug() << "exit clicked";

}
