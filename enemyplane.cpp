#include "enemyplane.h"

EnemyPlane::EnemyPlane(QPixmap pm, float ss, unsigned int h, float ms, PlayerPlane *p) :
    Actor(pm, ss, h), Plane(pm, ss, h, ms)
{
    player = p;

    // sight triangles
    //int triangleSide = pm.width()*5;
    int sightLength = pm.height()*3;
    int sightWidth = pm.width()*2;

    QPolygonF leftSightTriangle;
    leftSightTriangle.append(QPointF(-sightWidth + pm.width()/2, -sightLength));
    leftSightTriangle.append(QPointF(pm.width()/2, -sightLength));
    leftSightTriangle.append(QPointF(pm.width()/2, 0));
    leftSight = new QGraphicsPolygonItem(leftSightTriangle, this);

    QPolygonF rightSightTriangle;
    rightSightTriangle.append(QPointF(sightWidth + pm.width()/2, -sightLength));
    rightSightTriangle.append(QPointF(pm.width()/2, -sightLength));
    rightSightTriangle.append(QPointF(pm.width()/2, 0));
    rightSight = new QGraphicsPolygonItem(rightSightTriangle, this);

    // firing line rectangle
    int lineWidth = pm.width()/2;
    int lineHeight = pm.height()*7;
    firingLine = new QGraphicsRectItem(
        pm.width()/2-lineWidth/2, -lineHeight+pm.height(),
        lineWidth, lineHeight, this
    );
}

bool EnemyPlane::wantToTurnRight()
{
    return rightSight->collidesWithItem(player);
}

bool EnemyPlane::wantToTurnLeft()
{
    return leftSight->collidesWithItem(player);
}

bool EnemyPlane::wantToShoot()
{
    return firingLine->collidesWithItem(player);;
}
