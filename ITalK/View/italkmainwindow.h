#ifndef ITALKMAINWINDOW_H
#define ITALKMAINWINDOW_H

#include <QMainWindow>


class iTalKMainWindow : public QDialog
{
    Q_OBJECT
    
public:
    explicit iTalKMainWindow(QWidget *parent = 0);
    ~iTalKMainWindow();
    
private:
    QTabWidget *italkWidgets;
};

#endif // ITALKMAINWINDOW_H
