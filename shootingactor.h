#ifndef SHOOTINGACTOR_H
#define SHOOTINGACTOR_H

#include "actor.h"

class ShootingActor : Actor
{
private:
    float shootingRate;
    float shootingSpeed;
public:
    virtual void shoot() = 0;
};

#endif // SHOOTINGACTOR_H
