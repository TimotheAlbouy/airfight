#include "playerplane.h"
#include <QKeyEvent>
#include <QDebug>

PlayerPlane::PlayerPlane(QGraphicsSimpleTextItem *id) :
    Actor(QPixmap(":/res/player-plane.png").scaled(96, 96, Qt::KeepAspectRatio), 1.5, 10, new QMovie(":/res/explosion.gif"), 156, 228),
    Plane(QPixmap(), 0, 0, 6)
{
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
    infoDisplay = id;
    updateInfo();
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

void PlayerPlane::raiseScore()
{
    score += 1;
    updateInfo();
}

void PlayerPlane::updateInfo()
{
    QString text = QString("Health: %1\nScore: %2").arg(health).arg(score);
    infoDisplay->setText(text);
}

void PlayerPlane::loseHealth()
{
    Plane::loseHealth();
    updateInfo();
}

void PlayerPlane::gainHealth()
{
    Plane::gainHealth();
    updateInfo();
}

QDebug operator<<(QDebug debug, const PlayerPlane *plane)
{
    QDebugStateSaver saver(debug);
    QPointF pos = plane->scenePos();
    debug.nospace() << "PlayerPlane(health=" << plane->health << "," <<
                       "pos=(" << pos.x() << "," << pos.y() << ")," <<
                       "score=" << plane->score << ")";
    return debug;
}
