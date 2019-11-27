#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QScrollBar>
#include <QLoggingCategory>

#include "game.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QLoggingCategory::setFilterRules("*.debug=true\n"
                                     "qt.qpa.input*=false\n"
                                     "qt.widgets*=false");

    Game *game = new Game();

    const unsigned int width = 1000;
    const unsigned int height = 1000;

    QGraphicsView view(game);
    view.setFixedSize(width, height);
    view.setSceneRect(0, 0, width, height);
    view.fitInView(0, 0, width, height, Qt::KeepAspectRatio);
    view.setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view.setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //view.verticalScrollBar()->setEnabled(false);
    //view.horizontalScrollBar()->setEnabled(false);
    view.show();
    QPixmap background(":/res/background.png");
    view.setBackgroundBrush(background);

    game->setPlayerFocus();

    return a.exec();
}
