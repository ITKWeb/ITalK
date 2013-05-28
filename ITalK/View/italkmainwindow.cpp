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
        MainPage *chooseGroup = new MainPage(this);
        italkWidgets->addTab(chooseGroup, *icone, tr("Groupes"));
        italkWidgets->setTabIcon(0, *icone);

        QObject::connect(chooseGroup, SIGNAL(startConversation(Group)), this, SLOT(startDiscussion(Group)));


        QVBoxLayout *mainLayout = new QVBoxLayout;
        mainLayout->addWidget(italkWidgets);
        setLayout(mainLayout);


        setWindowTitle(tr("iTalK"));
 }



void iTalKMainWindow::startDiscussion(Group group) {

    qDebug() << "new discussion";
    Discussion *newDiscussion = new Discussion(group);
   int correspondingTab = italkWidgets->addTab(newDiscussion, group.getTitre());
   newDiscussion->setCorrespondingTab(correspondingTab);
   QObject::connect(newDiscussion, SIGNAL(exit()), this, SLOT(close()));

}

void iTalKMainWindow::close() {
    QObject * emetteur = sender();

        // On caste le sender en ce que nous supposons qu'il soit
    Discussion * emetteurCasted = qobject_cast<Discussion*>(emetteur);
    italkWidgets->removeTab(emetteurCasted->getCorrespondingTab());
}
