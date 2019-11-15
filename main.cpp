#include <QApplication>
#include <QGraphicsView>

//#include "mainwindow.h"
#include "game.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();

    Game *game = new Game();

    QGraphicsView *view = new QGraphicsView(game);
    view->setGeometry(QRect(50, 50, 400, 200));
    view->show();

    return a.exec();
}
