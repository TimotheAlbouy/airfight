#include "playerplane.h"
#include <QDebug>
#include <QKeyEvent>

void PlayerPlane::move()
{
    //qDebug() << "hallo";
    Plane::setTransformOriginPoint(Plane::boundingRect().center());
    QTransform t = Plane::transform();
    if (isRightPressed())
        t = t.rotate(steeringSpeed);
    if (isLeftPressed())
        t = t.rotate(-steeringSpeed);
    Plane::setTransform(t.translate(0, -movingSpeed));
    //Plane::setTransform(t.translate(0, -0.5));
}

void PlayerPlane::shoot()
{
    //if
}

void PlayerPlane::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
        case Qt::Key_Left : leftPressed = true; break;
        case Qt::Key_Right : rightPressed = true; break;
        case Qt::Key_Up : upPressed = true; break;
    }
}

void PlayerPlane::keyReleaseEvent(QKeyEvent *event)
{
    switch (event->key()) {
        case Qt::Key_Left : leftPressed = false; break;
        case Qt::Key_Right : rightPressed = false; break;
        case Qt::Key_Up : upPressed = false; break;
    }
}
