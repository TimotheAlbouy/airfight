#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>

#include "game.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Game *game = new Game();

    QGraphicsView *view = new QGraphicsView(game);
    view->setGeometry(50, 50, 1000, 1000);
    view->show();

    return a.exec();
}
