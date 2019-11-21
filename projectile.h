#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "movingactor.h"

class Projectile : public MovingActor
{
public:
    Projectile(QPixmap map) : Actor(map), MovingActor(map) { };
    void tick();
};

#endif // PROJECTILE_H
