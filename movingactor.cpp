#include <QDebug>

#include "movingactor.h"

MovingActor::MovingActor(float ms) :
    Actor(QPixmap(), 0, 0, nullptr, 0, 0)
{
    movingSpeed = ms;
}

void MovingActor::tick()
{
    Actor::tick();
    if (isOutOfBounds())
        handleOutOfBounds();
    move();
}

bool MovingActor::isOutOfBounds()
{
    QRectF rect = boundingRect();
    QPointF pos = mapToScene(rect.width()/2, 0);
    qreal sceneWidth = scene()->width();
    qreal sceneHeight = scene()->height();
    return pos.x() < -rect.height() ||
           pos.x() > sceneWidth + rect.height() ||
           pos.y() < -rect.height() ||
           pos.y() > sceneHeight + rect.height();
}

void MovingActor::move()
{
    QTransform trsf;
    trsf.translate(0, -movingSpeed);
    setTransform(trsf, true);
}

QDebug operator<<(QDebug debug, const MovingActor *actor)
{
    QDebugStateSaver saver(debug);
    QPointF pos = actor->scenePos();
    debug.nospace() << "MovingActor(health=" << actor->health << ", pos=(" << pos.x() << "," << pos.y() << "))";
    return debug;
}
