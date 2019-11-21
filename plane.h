#ifndef PLANE_H
#define PLANE_H

#include "movingactor.h"

class Plane : public MovingActor
{
public:
    Plane(QPixmap map) : Actor(map), MovingActor(map) { };
};

#endif // PLANE_H
