#ifndef MOVINGACTOR_H
#define MOVINGACTOR_H

#include "actor.h"

class MovingActor : virtual public Actor
{
protected:
    float movingSpeed = 5;
    float steeringSpeed = 5;
public:
    MovingActor(QPixmap map, float ms=5, float ss=5) : Actor(map) {
        movingSpeed = ms;
        steeringSpeed = ss;
    };
    void tick() { move(); };
    virtual void move() = 0;
};

#endif // MOVINGACTOR_H
