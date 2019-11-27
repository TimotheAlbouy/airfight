#ifndef PLANE_H
#define PLANE_H

#include "movingactor.h"

class Plane : public MovingActor
{
public:
    Plane(QPixmap pm) : Actor(pm), MovingActor(pm) { }

    void handleOutOfBounds() {
        transformRotate(180);
    }
};

#endif // PLANE_H
