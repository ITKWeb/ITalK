#include <QtGui/QApplication>
#include "View/italkmainwindow.h"
#include "networkmanager.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    iTalKMainWindow iTalK;
    iTalK.setMinimumSize(800,600);
    iTalK.show();
    new NetworkManager(5858);

    return a.exec();
}
