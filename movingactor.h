#ifndef MOVINGACTOR_H
#define MOVINGACTOR_H

#include <QDebug>

#include <QApplication>
#include <QDesktopWidget>

#include "actor.h"

class MovingActor : virtual public Actor
{
protected:
    float movingSpeed;
    float steeringSpeed;
public:
    MovingActor(QPixmap pm, float ms=5, float ss=3) : Actor(pm) {
        movingSpeed = ms;
        steeringSpeed = ss;
    }

    void tick() {
        if (isOutOfBounds())
            handleOutOfBounds();
        move();
    }

    bool isOutOfBounds() {
        QPointF pos = scenePos();
        QRectF rect = boundingRect();
        QRectF window = QApplication::desktop()->screenGeometry();
        return pos.x() < -window.width()/2 - rect.width() ||
               pos.x() > window.width()/2 ||
               pos.y() < -window.height()/2 - rect.height() ||
               pos.y() > window.height()/2;
    }

    void move() {
        QTransform t = transform();
        QRectF rect = boundingRect();

        t.translate(rect.width()/2, rect.height()/2);
        if (wantToGoRight())
            t.rotate(steeringSpeed);
        if (wantToGoLeft())
            t.rotate(-steeringSpeed);
        t.translate(-rect.width()/2, -rect.height()/2);

        t.translate(0, -movingSpeed);
        setTransform(t);
    }

    virtual void handleOutOfBounds() = 0;
    virtual bool wantToGoRight() = 0;
    virtual bool wantToGoLeft() = 0;
};

#endif // MOVINGACTOR_H
