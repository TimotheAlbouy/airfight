#include "playerplane.h"
#include <QKeyEvent>

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

bool PlayerPlane::wantToGoRight()
{
    return rightPressed;
}

bool PlayerPlane::wantToGoLeft()
{
    return leftPressed;
}

bool PlayerPlane::wantToShoot()
{
    return upPressed;
}
