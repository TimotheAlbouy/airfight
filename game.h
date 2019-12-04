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
    static const int AVERAGE_TICKS_ENEMY_SPAWN = 500;
    QTimer *timer;
    PlayerPlane *player;
    std::mt19937 rng;
    bool rngSeeded = false;
public:
    Game();
    void handleCollisions();
    void randomDrawSpawnEnemy();
    void spawnEnemy();
    int randInt(int min, int max);
public slots:
    void tick();
};

#endif // GAME_H
