#ifndef ITALKMAINWINDOW_H
#define ITALKMAINWINDOW_H

#include <QDialog>
#include <QTableWidget>
#include "group.h"


class iTalKMainWindow : public QDialog
{
    Q_OBJECT
    
public:
    iTalKMainWindow(QWidget *parent = 0);
    
public slots:
    void startDiscussion();

private:
    QTabWidget *italkWidgets;
};

#endif // ITALKMAINWINDOW_H
