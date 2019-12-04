#ifndef MOVINGACTOR_H
#define MOVINGACTOR_H

#include <QDebug>

#include <QGraphicsScene>
#include <QGraphicsView>

#include "actor.h"

class MovingActor : virtual public Actor
{
protected:
    float movingSpeed;
public:
    MovingActor(QPixmap pm, float ss, unsigned int h, float ms) : Actor(pm, ss, h) {
        movingSpeed = ms;
    }

    void tick() {
        Actor::tick();
        if (isOutOfBounds())
            handleOutOfBounds();
        move();
    }

    bool isOutOfBounds() {
        QRectF rect = boundingRect();
        QPointF pos = mapToScene(rect.width()/2, 0);
        qreal sceneWidth = scene()->width();
        qreal sceneHeight = scene()->height();
        return pos.x() < -rect.height() ||
               pos.x() > sceneWidth + rect.height() ||
               pos.y() < -rect.height() ||
               pos.y() > sceneHeight + rect.height();
    }

    void move() {
        QTransform trsf;
        trsf.translate(0, -movingSpeed);
        setTransform(trsf, true);
    }

    virtual void handleOutOfBounds() = 0;
};

#endif // MOVINGACTOR_H
