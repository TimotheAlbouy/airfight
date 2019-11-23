#ifndef PLANE_H
#define PLANE_H

#include "movingactor.h"

class Plane : public MovingActor
{
public:
    Plane(QPixmap pm) : Actor(pm), MovingActor(pm) { }

    void handleOutOfBounds() {
        QTransform t = transform();
        t.rotate(180);
        setTransform(t);
    }
};

#endif // PLANE_H
