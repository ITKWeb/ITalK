#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "networkmanager.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    new NetworkManager(5858);
}

MainWindow::~MainWindow()
{
    delete ui;
}
