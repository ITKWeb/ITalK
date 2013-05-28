#include "italkmainwindow.h"
#include <QtGui>


iTalKMainWindow::iTalKMainWindow(QWidget *parent) :
    QDialog(parent)
{  
        italkWidgets= new QTabWidget;
        italkWidgets->addTab(new MainPage(), tr("Groupes de discussion"));

        QVBoxLayout *mainLayout = new QVBoxLayout;
        mainLayout->setSizeConstraint(QLayout::SetNoConstraint);
        mainLayout->addWidget(italkWidgets);
        setLayout(mainLayout);

        setWindowTitle(tr("iTalK"));
 }



iTalKMainWindow::addDiscussion(Group group) {
    italkWidgets->addTab(new Conversation(group), tr("Discussion "+group.getNom()));
}
