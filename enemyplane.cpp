#include <QDebug>

#include "enemyplane.h"

EnemyPlane::EnemyPlane(PlayerPlane *p) :
    Actor(QPixmap(":/res/enemy-plane.png").scaled(96, 96, Qt::KeepAspectRatio), 1, 5, new QMovie(":/res/explosion.gif"), 156, 228),
    Plane(QPixmap(), 0, 0, 5)
{
    player = p;

    QRectF rect = boundingRect();
    int halfWidth = rect.width()/2;
    int sightWidth = rect.width()*2;
    int sightHeight = rect.height()*3;
    int lineWidth = rect.width()/2;
    int lineHeight = rect.height()*7;

    // left sight triangle
    QPolygonF leftSightTriangle;
    leftSightTriangle.append(QPointF(-sightWidth + halfWidth, -sightHeight));
    leftSightTriangle.append(QPointF(halfWidth, -sightHeight));
    leftSightTriangle.append(QPointF(halfWidth, 0));
    leftSight = new QGraphicsPolygonItem(leftSightTriangle, this);
    leftSight->hide();

    // right sight triangle
    QPolygonF rightSightTriangle;
    rightSightTriangle.append(QPointF(sightWidth + halfWidth, -sightHeight));
    rightSightTriangle.append(QPointF(halfWidth, -sightHeight));
    rightSightTriangle.append(QPointF(halfWidth, 0));
    rightSight = new QGraphicsPolygonItem(rightSightTriangle, this);
    rightSight->hide();

    // firing line rectangle
    firingLine = new QGraphicsRectItem(
        halfWidth - lineWidth/2, -lineHeight + rect.height(),
        lineWidth, lineHeight, this
    );
    firingLine->hide();
}

bool EnemyPlane::wantToTurnRight()
{
    // wants to turn right if the player is in the right sight
    if (rightSight->collidesWithItem(player))
        return true;
    // wants to turn right if another enemy plane is in the left sight
    for (QGraphicsItem *item : leftSight->collidingItems()) {
        EnemyPlane *plane = dynamic_cast<EnemyPlane*>(item);
        if (plane && plane != this)
            return true;
    }
    // else doesn't want to turn right
    return false;
}

bool EnemyPlane::wantToTurnLeft()
{
    // wants to turn left if the player is in the left sight
    if (leftSight->collidesWithItem(player))
        return true;
    // wants to turn left if another enemy plane is in the right sight
    for (QGraphicsItem *item : rightSight->collidingItems()) {
        EnemyPlane *plane = dynamic_cast<EnemyPlane*>(item);
        if (plane && plane != this)
            return true;
    }
    // else doesn't want to turn left
    return false;
}

bool EnemyPlane::wantToShoot()
{
    return firingLine->collidesWithItem(player);;
}

void EnemyPlane::die()
{
    player->raiseScore();
    Plane::die();
}

QDebug operator<<(QDebug debug, const EnemyPlane *plane)
{
    QDebugStateSaver saver(debug);
    QPointF pos = plane->scenePos();
    debug.nospace() << "EnemyPlane(health=" << plane->health << ", pos=(" << pos.x() << "," << pos.y() << "))";
    return debug;
}
