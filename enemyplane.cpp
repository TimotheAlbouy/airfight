#include "enemyplane.h"

EnemyPlane::EnemyPlane(QPixmap pm, float ss, unsigned int h, float ms, PlayerPlane *p) :
    Actor(pm, ss, h), Plane(pm, ss, h, ms)
{
    player = p;

    // turning rectangles
    int rectWidth = pm.width()*5;
    int rectHeight = pm.height()*5;
    leftRect = new QGraphicsRectItem(
        -rectWidth+pm.width()/2, -rectHeight+pm.height(),
        rectWidth, rectHeight, this
    );
    rightRect = new QGraphicsRectItem(
        pm.width()/2, -rectHeight+pm.height(),
        rectWidth, rectHeight, this
    );

    // firing rectangle
    int lineWidth = pm.width()/2;
    int lineHeight = pm.height()*7;
    firingLine = new QGraphicsRectItem(
        pm.width()/2-lineWidth/2, -lineHeight+pm.height(),
        lineWidth, lineHeight, this
    );
}

bool EnemyPlane::wantToTurnRight()
{
    return rightRect->collidesWithItem(player);
}

bool EnemyPlane::wantToTurnLeft()
{
    return leftRect->collidesWithItem(player);
}

bool EnemyPlane::wantToShoot()
{
    return firingLine->collidesWithItem(player);;
}
