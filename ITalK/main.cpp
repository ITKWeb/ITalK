#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    iTalKMainWindow iTalK;
    iTalK.show();
    
    return a.exec();
}
