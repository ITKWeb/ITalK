#ifndef DISCUSSIONWIDGET_H
#define DISCUSSIONWIDGET_H

#include <QWidget>

namespace Ui {
class DiscussionWidget;
}

class DiscussionWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit DiscussionWidget(QWidget *parent = 0);
    ~DiscussionWidget();
    
private:
    Ui::DiscussionWidget *ui;
};

#endif // DISCUSSIONWIDGET_H
