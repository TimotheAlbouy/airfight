#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "movingactor.h"

class Projectile : public MovingActor
{
public:
    Projectile();
    void tick();
};

#endif // PROJECTILE_H
