#ifndef ENEMYPLANE_H
#define ENEMYPLANE_H

#include "plane.h"
#include "playerplane.h"

class EnemyPlane : public Plane
{
protected:
    PlayerPlane *player;
    QGraphicsPolygonItem *leftSight;
    QGraphicsPolygonItem *rightSight;
    QGraphicsRectItem *firingLine;
public:
    EnemyPlane(QPixmap pm, float ss, unsigned int h, float ms, PlayerPlane *p);
    bool wantToTurnRight();
    bool wantToTurnLeft();
    bool wantToShoot();
};

#endif // ENEMYPLANE_H
