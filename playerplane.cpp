#include "playerplane.h"
#include <QDebug>
#include <QKeyEvent>

void PlayerPlane::move()
{
    QTransform t = Actor::transform();
    QRectF rect = Actor::boundingRect();
    t.translate(rect.width()/2, rect.height()/2);
    if (isRightPressed())
        t.rotate(steeringSpeed);
    if (isLeftPressed())
        t.rotate(-steeringSpeed);
    t.translate(-rect.width()/2, -rect.height()/2);
    t.translate(0, -movingSpeed);
    Actor::setTransform(t);
}

void PlayerPlane::shoot()
{
    //if
}

void PlayerPlane::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
        case Qt::Key_Left :
            leftPressed = true;
            break;
        case Qt::Key_Right :
            rightPressed = true;
            break;
        case Qt::Key_Up :
            upPressed = true;
            break;
    }
}

void PlayerPlane::keyReleaseEvent(QKeyEvent *event)
{
    switch (event->key()) {
        case Qt::Key_Left :
            leftPressed = false;
            break;
        case Qt::Key_Right :
            rightPressed = false;
            break;
        case Qt::Key_Up :
            upPressed = false;
            break;
    }
}
