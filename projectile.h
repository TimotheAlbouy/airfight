#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "movingactor.h"

class ShootingActor; // forward declaration to prevent circular dependency

class Projectile : public MovingActor
{
protected:
    ShootingActor *shooter;
public:
    Projectile(QPixmap pm, ShootingActor *s) :
        Actor(pm, 0, 1), MovingActor(pm, 0, 1, 15)
    {
        shooter = s;
    }

    bool wantToTurnRight()
    {
        return false;
    }

    bool wantToTurnLeft()
    {
        return false;
    }

    void handleOutOfBounds()
    {
        die();
    }
};

#endif // PROJECTILE_H
