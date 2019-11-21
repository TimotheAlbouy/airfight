#ifndef ENEMYPLANE_H
#define ENEMYPLANE_H

#include "plane.h"

class EnemyPlane : public Plane
{
public:
    EnemyPlane(QPixmap map) : Actor(map), Plane(map) { };
    void move();
    //void operator += (float a);
};

#endif // ENEMYPLANE_H
