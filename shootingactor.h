#ifndef SHOOTINGACTOR_H
#define SHOOTINGACTOR_H

#include "actor.h"

class ShootingActor : virtual public Actor
{
private:
    float shootingRate;
    float projectileSpeed;
public:
    ShootingActor(QPixmap map, float sr=5, float ps=5) : Actor(map) {
        shootingRate = sr;
        projectileSpeed = ps;
    };
    void tick() {
        shoot();
    };
    virtual void shoot() = 0;
};

#endif // SHOOTINGACTOR_H
