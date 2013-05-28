#ifndef ITALKMAINWINDOW_H
#define ITALKMAINWINDOW_H

#include <QDialog>


class iTalKMainWindow : public QDialog
{
    Q_OBJECT
    
public:
    iTalKMainWindow(QWidget *parent = 0);
    
private:
    QTabWidget *italkWidgets;
};

#endif // ITALKMAINWINDOW_H
