#ifndef MOVINGACTOR_H
#define MOVINGACTOR_H

#include "actor.h"

class MovingActor : public Actor
{
private:
    const float movingSpeed = 5;
    const float steeringSpeed = 5;
public:
    virtual void move() = 0;
};

#endif // MOVINGACTOR_H
