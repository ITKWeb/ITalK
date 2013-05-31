#ifndef DISCUSSION_H
#define DISCUSSION_H

#include <QWidget>
#include "group.h"
#include "message.h"

namespace Ui {
class Discussion;
}

class Discussion : public QWidget
{
    Q_OBJECT
    
private:
    Ui::Discussion *ui;
//    int tabId;
    QString name;

public:

    User moi;
    Group currentDiscussion;

    explicit Discussion(User me, Group group, QWidget *parent = 0);
    ~Discussion();   
//    void setCorrespondingTab(int tabId);
//    int getCorrespondingTab();

signals:
    void exit(QString groupId);

public slots:
    void on_exitGroupButton_clicked();
    void envoyerMessage();
    void afficherMessage(Message m);
 };

#endif // DISCUSSION_H
