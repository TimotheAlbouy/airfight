#ifndef PLANE_H
#define PLANE_H

#include "movingactor.h"
#include <QApplication>
#include <QDesktopWidget>
#include <QDebug>

class Plane : public MovingActor
{
public:
    Plane(QPixmap map) : Actor(map), MovingActor(map) { };
    void tick() {
        MovingActor::tick();
        checkIfOutOfBounds();
    };
    void checkIfOutOfBounds() {
        QPointF pos = scenePos();
        QRectF rect = boundingRect();
        QRectF parentRect = QApplication::desktop()->screenGeometry();
        QTransform t = transform();
        qDebug() << "x: " << pos.x() << "; y: " << pos.y();
        qDebug() << "width: " << rect.width() << "; height: " << rect.height();
        qDebug() << "parent width: " << parentRect.width() << "; parent height: " << parentRect.height();
        qDebug() << "";
        if (pos.x() < 0 - rect.width() || pos.x() > parentRect.width() ||
            pos.y() < 0 - rect.height() || pos.y() > parentRect.height())
            t.rotate(180);
        setTransform(t);
    }
};

#endif // PLANE_H
