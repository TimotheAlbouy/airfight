#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "movingactor.h"

class ShootingActor; // forward declaration to prevent circular dependency

class Projectile : public MovingActor
{
protected:
    ShootingActor *shooter;
public:
    Projectile(QPixmap pm, ShootingActor *s) : Actor(pm), MovingActor(pm) {
        shooter = s;
    }

    bool wantToGoRight() {
        return false;
    }

    bool wantToGoLeft() {
        return false;
    }

    void handleOutOfBounds();
};

#endif // PROJECTILE_H
