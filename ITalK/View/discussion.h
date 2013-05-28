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
    
public:
    explicit Discussion(Group &group, QWidget *parent = 0);
    ~Discussion();
    
private:
    Ui::Discussion *ui;
};

#endif // DISCUSSION_H
