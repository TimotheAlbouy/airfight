#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;

    //Game *game = new Game();

    //QGraphicsView *view = new QGraphicsView(this);
    //view->setGeometry(QRect(50, 50, 400, 200));
    //view->show();
}
