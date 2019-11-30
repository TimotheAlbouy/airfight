#ifndef PLAYERPLANE_H
#define PLAYERPLANE_H

#include "plane.h"

class PlayerPlane : public Plane
{
private:
    bool leftPressed = false;
    bool rightPressed = false;
    bool upPressed = false;
public:
    PlayerPlane(QPixmap pm, float ss, unsigned int h, float ms);
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    bool wantToTurnRight();
    bool wantToTurnLeft();
    bool wantToShoot();
};

#endif // PLAYERPLANE_H
