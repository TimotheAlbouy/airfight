#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>

#include "plane.h"

class Game : public QGraphicsScene
{
private:
    int width;
    int height;
    QTimer *timer;
    Plane *player;

public:
    Game();
    //void initialize();
    //void run();

public slots:
    void tick();
};

#endif // GAME_H
