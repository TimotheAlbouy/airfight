#ifndef MOVINGACTOR_H
#define MOVINGACTOR_H

#include <QDebug>

#include <QApplication>
#include <QDesktopWidget>
#include <QGraphicsScene>

#include "actor.h"

class MovingActor : virtual public Actor
{
protected:
    float movingSpeed;
public:
    MovingActor(QPixmap pm, float ms=5) : Actor(pm) {
        movingSpeed = ms;
    }

    void tick() {
        Actor::tick();
        if (isOutOfBounds())
            handleOutOfBounds();
        move();
    }

    bool isOutOfBounds() {
        QPointF pos = scenePos();
        QRectF rect = boundingRect();
        qreal sceneWidth = scene()->width();
        qreal sceneHeight = scene()->height();
        qDebug() << "width: " << sceneWidth << "; height: " << sceneHeight;
        return pos.x() < -sceneWidth/2 - rect.width() ||
               pos.x() > sceneWidth/2 ||
               pos.y() < -sceneHeight/2 - rect.height() ||
               pos.y() > sceneHeight/2;
    }

    void move() {
        QTransform t = transform();
        t.translate(0, -movingSpeed);
        setTransform(t);
    }

    virtual void handleOutOfBounds() = 0;
};

#endif // MOVINGACTOR_H
