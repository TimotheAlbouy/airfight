#ifndef MOVINGACTOR_H
#define MOVINGACTOR_H

#include "actor.h"

class MovingActor : Actor
{
private:
    float movingSpeed;
    float directionAngle;
public:
    virtual void move() = 0;
};

#endif // MOVINGACTOR_H
