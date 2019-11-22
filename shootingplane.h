#ifndef SHOOTINGPLANE_H
#define SHOOTINGPLANE_H

#include "plane.h"
#include "shootingactor.h"
#include <QDebug>

class ShootingPlane : public Plane, public ShootingActor
{
public:
    ShootingPlane(QPixmap map) : Actor(map), Plane(map), ShootingActor(map) { };
    void tick() {
        move();
        shoot();
        checkIfOutOfBounds();
    };
};

#endif // SHOOTINGPLANE_H
