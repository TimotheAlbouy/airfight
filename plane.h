#ifndef PLANE_H
#define PLANE_H

#include "movingactor.h"
#include "shootingactor.h"

class Plane : public MovingActor, public ShootingActor
{
public:
    Plane(QPixmap pm, float ss, unsigned int h, float ms) :
        Actor(pm, ss, h), MovingActor(pm, ss, h, ms), ShootingActor(pm, ss, h, 10, 5) { }

    void tick()
    {
        ShootingActor::tick();
        MovingActor::tick();
    }

    void handleOutOfBounds()
    {
        transformRotate(180);
    }
};

#endif // PLANE_H
