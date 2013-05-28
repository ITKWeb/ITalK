#ifndef USERPRESENTATIONFORM_H
#define USERPRESENTATIONFORM_H

#include <QWidget>

namespace Ui {
class UserPresentationForm;
}

class UserPresentationForm : public QWidget
{
    Q_OBJECT
    
public:
    explicit UserPresentationForm(QWidget *parent = 0);
    ~UserPresentationForm();
    
private:
    Ui::UserPresentationForm *ui;
};

#endif // USERPRESENTATIONFORM_H
