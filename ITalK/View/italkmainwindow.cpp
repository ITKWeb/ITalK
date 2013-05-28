#include "italkmainwindow.h"
#include <QtGui>
#include <QIcon>
#include <QLabel>
#include <QImage>
#include <QPixmap>
#include "mainpage.h"
#include "discussion.h"
#include "group.h"
#include "user.h"

iTalKMainWindow::iTalKMainWindow(QWidget *parent) :
    QDialog(parent)
{  
        italkWidgets= new QTabWidget;
        QIcon *icone = new QIcon(":/home.png");
        italkWidgets->addTab(new MainPage(), *icone, tr("Groupes"));
        italkWidgets->setTabIcon(0, *icone);

    // TEST
        QList<User> users;
        User moi(tr("Pineau"), tr("Jef"), tr("info"), tr("dev"), tr(""), tr(""), tr(""));
        users.append(moi);
        Group group(tr("1"), tr("Groupe Moi"), users);
    //test

        italkWidgets->addTab(new Discussion(group), group.getTitre());

        QVBoxLayout *mainLayout = new QVBoxLayout;
        mainLayout->addWidget(italkWidgets);
        setLayout(mainLayout);

        setWindowTitle(tr("iTalK"));
 }



void iTalKMainWindow::addDiscussion(Group &group) {
   italkWidgets->addTab(new Discussion(group), group.getTitre());
}
