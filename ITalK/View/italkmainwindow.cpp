#include "italkmainwindow.h"
#include <QtGui>
#include <QIcon>
#include <QLabel>
#include <QImage>
#include <QPixmap>
#include "mainpage.h"
#include "discussion.h"
#include "group.h"


iTalKMainWindow::iTalKMainWindow(QWidget *parent) :
    QDialog(parent)
{  
        italkWidgets= new QTabWidget;
        QIcon *icone = new QIcon(QPixmap("home.png"));
        italkWidgets->addTab(new MainPage(), *icone, tr("Groupes"));
        italkWidgets->setTabIcon(0, *icone);

        QVBoxLayout *mainLayout = new QVBoxLayout;
        mainLayout->addWidget(italkWidgets);
        setLayout(mainLayout);

        setWindowTitle(tr("iTalK"));
 }



void iTalKMainWindow::addDiscussion(Group &group) {
   italkWidgets->addTab(new Discussion(group), group.getTitre());
}
