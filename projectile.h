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
    void move();
};

#endif // PROJECTILE_H
