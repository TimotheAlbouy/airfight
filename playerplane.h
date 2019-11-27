#ifndef PLAYERPLANE_H
#define PLAYERPLANE_H

#include "shootingplane.h"

class PlayerPlane : public ShootingPlane
{
private:
    bool leftPressed = false;
    bool rightPressed = false;
    bool upPressed = false;
public:
    PlayerPlane(QPixmap pm) : Actor(pm), ShootingPlane(pm) { }
    void shoot();
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    bool wantToTurnRight();
    bool wantToTurnLeft();
    bool wantToShoot();
};

#endif // PLAYERPLANE_H
