#include "playerplane.h"
#include <QKeyEvent>

PlayerPlane::PlayerPlane(QPixmap pm, float ss, unsigned int h, float ms) :
    Actor(pm, ss, h), Plane(pm, ss, h, ms)
{ }

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

bool PlayerPlane::wantToTurnRight()
{
    return rightPressed;
}

bool PlayerPlane::wantToTurnLeft()
{
    return leftPressed;
}

bool PlayerPlane::wantToShoot()
{
    return upPressed;
}
