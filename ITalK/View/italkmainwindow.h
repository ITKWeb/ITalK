#ifndef ITALKMAINWINDOW_H
#define ITALKMAINWINDOW_H

#include <QDialog>
#include <QTableWidget>
#include <QMap>
#include <QStringList>
#include "user.h"
#include "group.h"


class iTalKMainWindow : public QDialog
{
    Q_OBJECT
    
public:
    iTalKMainWindow(QWidget *parent = 0);
    User *moi;

public slots:
    void startDiscussion(Group group);
    void close(QString groupId);

private:
    QTabWidget *italkWidgets;
    QStringList *tabList;
};

#endif // ITALKMAINWINDOW_H
