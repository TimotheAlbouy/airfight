#ifndef SHOOTINGACTOR_H
#define SHOOTINGACTOR_H

#include "actor.h"

class ShootingActor : public Actor
{
private:
    const float shootingRate = 5;
    const float projectileSpeed = 5;
public:
    ShootingActor(QPixmap map) : QGraphicsPixmapItem(map) { };
    virtual void shoot() = 0;
};

#endif // SHOOTINGACTOR_H
