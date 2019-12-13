#include <QDebug>
#include <QMovie>

#include "projectile.h"

Projectile::Projectile(ShootingActor *s) :
    Actor(QPixmap(":/res/projectile.png"), 0, 1, new QMovie(":/res/hit.gif"), 30, 30),
    MovingActor(15)
{
    shooter = s;
}

bool Projectile::wantToTurnRight()
{
    return false;
}

bool Projectile::wantToTurnLeft()
{
    return false;
}

void Projectile::handleOutOfBounds()
{
    die();
}

QDebug operator<<(QDebug debug, const Projectile *projectile)
{
    QDebugStateSaver saver(debug);
    QPointF pos = projectile->scenePos();
    debug.nospace() << "Projectile(health=" << projectile->health << ", pos=(" << pos.x() << "," << pos.y() << "))";
    return debug;
}
