#ifndef DISCUSSION_H
#define DISCUSSION_H

#include <QWidget>
#include "group.h"

namespace Ui {
class Discussion;
}

class Discussion : public QWidget
{
    Q_OBJECT
    
private:
    Ui::Discussion *ui;
    int tabId;

public:
    explicit Discussion(Group &group, QWidget *parent = 0);
    ~Discussion();   
    void setCorrespondingTab(int tabId);
    int getCorrespondingTab();

signals:
    void exit();

public slots:
    void on_exitGroupButton_clicked();
    void afficherMessage();
 };

#endif // DISCUSSION_H
