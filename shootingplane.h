#ifndef SHOOTINGPLANE_H
#define SHOOTINGPLANE_H

#include "plane.h"
#include "shootingactor.h"

class ShootingPlane : public Plane, public ShootingActor
{
public:
    ShootingPlane(QPixmap pm) : Actor(pm), Plane(pm), ShootingActor(pm) { }
    void tick() {
        ShootingActor::tick();
        Plane::tick();
    }
};

#endif // SHOOTINGPLANE_H
