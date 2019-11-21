#ifndef PLAYERPLANE_H
#define PLAYERPLANE_H

#include "shootingplane.h"

class PlayerPlane : public ShootingPlane
{
private:
    bool leftPressed = false;
    bool rightPressed = false;
    bool upPressed = false;
    bool isLeftPressed() { return leftPressed; };
    bool isRightPressed() { return rightPressed; };
    bool isUpPressed() { return upPressed; };
public:
    PlayerPlane(QPixmap map) : Actor(map), ShootingPlane(map) { };
    void move();
    void shoot();
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
};

#endif // PLAYERPLANE_H
