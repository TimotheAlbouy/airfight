#ifndef PLANE_H
#define PLANE_H

#include "movingactor.h"
#include <QApplication>
#include <QDesktopWidget>
#include <QDebug>

class Plane : public MovingActor
{
public:
    Plane(QPixmap pm) : Actor(pm), MovingActor(pm) { }
    void tick() {
        MovingActor::tick();
        checkIfOutOfBounds();
    }
    void checkIfOutOfBounds() {
        QPointF pos = scenePos();
        QRectF rect = boundingRect();
        QRectF window = QApplication::desktop()->screenGeometry();
        QTransform t = transform();
        qDebug() << "pos: " << pos;
        if (pos.x() < -window.width()/2 - rect.width() ||
            pos.x() > window.width()/2 ||
            pos.y() < -window.height()/2 - 5*rect.height() ||
            pos.y() > window.height()/2)
            t.rotate(180);
        setTransform(t);
    }
    void move() {
        QTransform t = Actor::transform();
        QRectF rect = Actor::boundingRect();
        t.translate(rect.width()/2, rect.height()/2);
        if (wantToGoRight())
            t.rotate(steeringSpeed);
        if (wantToGoLeft())
            t.rotate(-steeringSpeed);
        t.translate(-rect.width()/2, -rect.height()/2);
        t.translate(0, -movingSpeed);
        Actor::setTransform(t);
    }
    virtual bool wantToGoRight() = 0;
    virtual bool wantToGoLeft() = 0;
};

#endif // PLANE_H
