#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>

#include "playerplane.h"

class Game : public QGraphicsScene
{
    Q_OBJECT
private:
    int width;
    int height;
    QTimer *timer;
    PlayerPlane *player;
    std::vector<Actor*> actors;
public:
    Game();
    void setPlayerFocus();
public slots:
    void tick();
};

#endif // GAME_H
