#ifndef PLANE_H
#define PLANE_H

#include "movingactor.h"

class Plane : public MovingActor
{
public:
    Plane(QPixmap map);
    void move();
    //void operator += (float a);
};

#endif // PLANE_H
