#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>

#include "playerplane.h"

class Game : public QGraphicsScene
{
    Q_OBJECT
private:
    static const int WIDTH = 1000;
    static const int HEIGHT = 1000;
    QTimer *timer;
    PlayerPlane *player;
    //std::mt19937 rng(std::random_device()());
    std::mt19937 rng;
    bool rngSeeded = true;
public:
    Game();
    void handleCollisions();
    void spawnEnemy();
    int randInt(int min, int max);
public slots:
    void tick();
};

#endif // GAME_H
