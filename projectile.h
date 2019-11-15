#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "movingactor.h"

class Projectile : MovingActor
{
public:
    Projectile();
    void tick();
};

#endif // PROJECTILE_H
