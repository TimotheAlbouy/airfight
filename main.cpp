#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>

#include "game.h"
#include <QLoggingCategory>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QLoggingCategory::setFilterRules("*.debug=true\n"
                                     "qt.qpa.input*=false\n"
                                     "qt.widgets*=false");

    Game *game = new Game();

    QGraphicsView view(game);
    view.setGeometry(50, 50, 1000, 1000);
    view.show();

    game->setPlayerFocus();

    return a.exec();
}
