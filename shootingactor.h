#ifndef SHOOTINGACTOR_H
#define SHOOTINGACTOR_H

#include "actor.h"

class ShootingActor : Actor
{
private:
    float shootingRate;
    float shootingSpeed;
public:
    void shoot();
};

#endif // SHOOTINGACTOR_H
