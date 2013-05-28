#ifndef HOMETABWIDGET_H
#define HOMETABWIDGET_H

#include <QTabWidget>

namespace Ui {
class HomeTabWidget;
}

class HomeTabWidget : public QTabWidget
{
    Q_OBJECT
    
public:
    explicit HomeTabWidget(QWidget *parent = 0);
    ~HomeTabWidget();
    
private:
    Ui::HomeTabWidget *ui;
};

#endif // HOMETABWIDGET_H
