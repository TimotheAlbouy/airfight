#ifndef ENEMYPLANE_H
#define ENEMYPLANE_H

#include "plane.h"

class EnemyPlane : public Plane
{
public:
    EnemyPlane(QPixmap pm) : Actor(pm), Plane(pm) { }
    bool wantToTurnRight();
    bool wantToTurnLeft();
    //void operator += (float a);
};

#endif // ENEMYPLANE_H
