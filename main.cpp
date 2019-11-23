#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QScrollBar>
#include <QLoggingCategory>

#include "game.h"

class GameView : public QGraphicsView
{
public:
    GameView(Game* g) : QGraphicsView(g) { }
    void scrollContentsBy(int, int) override { }
};

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QLoggingCategory::setFilterRules("*.debug=true\n"
                                     "qt.qpa.input*=false\n"
                                     "qt.widgets*=false");

    Game *game = new Game();

    GameView view(game);
    view.setFixedSize(1000, 1000);
    //view.verticalScrollBar()->setEnabled(false);
    //view.horizontalScrollBar()->setEnabled(false);
    view.show();
    QPixmap background(":/res/background.png");
    view.setBackgroundBrush(background);

    game->setPlayerFocus();

    return a.exec();
}
