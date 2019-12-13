#include <QDebug>
#include <QSound>

#include "plane.h"

Plane::Plane(QPixmap pm, float ss, unsigned int h, float ms) :
    Actor(pm, ss, h, new QMovie(":/res/explosion.gif"), 156, 228),
    MovingActor(ms),
    ShootingActor(10, 5)
{ }

void Plane::tick()
{
    ShootingActor::tick();
    MovingActor::tick();
}

void Plane::handleOutOfBounds()
{
    transformRotate(180);
}

void Plane::die()
{
    QSound::play(":/res/explosion.wav");
    MovingActor::die();
}

QDebug operator<<(QDebug debug, const Plane *plane)
{
    QDebugStateSaver saver(debug);
    QPointF pos = plane->scenePos();
    debug.nospace() << "Plane(health=" << plane->health
                    << ", pos=(" << pos.x() << ","
                    << pos.y() << "))";
    return debug;
}
