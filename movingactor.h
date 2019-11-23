#ifndef MOVINGACTOR_H
#define MOVINGACTOR_H

#include "actor.h"

class MovingActor : virtual public Actor
{
protected:
    float movingSpeed;
    float steeringSpeed;
public:
    MovingActor(QPixmap pm, float ms=5, float ss=3) : Actor(pm) {
        movingSpeed = ms;
        steeringSpeed = ss;
    }
    void tick() {
        move();
    }
    virtual void move() = 0;
};

#endif // MOVINGACTOR_H
