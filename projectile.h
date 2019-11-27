#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "movingactor.h"

class ShootingActor; // forward declaration to prevent circular dependency

class Projectile : public MovingActor
{
protected:
    ShootingActor *shooter;
public:
    Projectile(QPixmap pm, ShootingActor *s) : Actor(pm), MovingActor(pm, 15) {
        shooter = s;
    }

    bool wantToTurnRight() {
        return false;
    }

    bool wantToTurnLeft() {
        return false;
    }

    void handleOutOfBounds() {
        scene()->removeItem(this);
        //delete this;
    }
};

#endif // PROJECTILE_H
