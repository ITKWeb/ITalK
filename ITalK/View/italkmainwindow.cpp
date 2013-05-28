#include "italkmainwindow.h"
#include <QtGui>
#include <QIcon>
#include <QLabel>
#include <QImage>
#include <QPixmap>
#include "mainpage.h"


iTalKMainWindow::iTalKMainWindow(QWidget *parent) :
    QDialog(parent)
{  
        italkWidgets= new QTabWidget;
        QLabel *image = new QLabel();
        image->setPixmap(QPixmap("icone.png"));
        QIcon *icone = new QIcon(QPixmap("icone.png"));
        italkWidgets->addTab(new MainPage(), *icone, tr("Groupes"));


        QVBoxLayout *mainLayout = new QVBoxLayout;
        mainLayout->setSizeConstraint(QLayout::SetNoConstraint);
        mainLayout->addWidget(italkWidgets);
        mainLayout->addWidget(image);
        setLayout(mainLayout);

        setWindowTitle(tr("iTalK"));
 }



void iTalKMainWindow::addDiscussion(Group group) {
   //italkWidgets->addTab(new Conversation(group), tr("Discussion "+group.getNom()));
}
