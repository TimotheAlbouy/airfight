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

public:
    Game();
    void setPlayerFocus();
    //void initialize();
    //void run();

public slots:
    void tick();
};

#endif // GAME_H
