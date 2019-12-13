#include <QDebug>
//#include <QSound>

#include "shootingactor.h"

ShootingActor::ShootingActor(unsigned int tps, float ps) :
    Actor(QPixmap(), 0, 0, nullptr, 0, 0)
{
    ticksPerShoot = tps;
    ticksAfterLastShoot = tps;
    projectileSpeed = ps;
}

void ShootingActor::tick()
{
    Actor::tick();
    if (wantToShoot() && ticksAfterLastShoot >= ticksPerShoot)
        shoot();
    ticksAfterLastShoot++;
}

void ShootingActor::shoot()
{
    Projectile *p = new Projectile(this);
    QRectF planeRect = boundingRect();
    QRectF projectileRect = p->boundingRect();
    QPointF pos = mapToScene(
        QPointF(
            planeRect.width()/2-projectileRect.width()/2,
            -1.5*projectileRect.height()
        )
    );

    p->setPos(pos);
    p->transformRotate(transformRotation);
    scene()->addItem(p);
    projectiles.push_back(p);
    //QSound::play(QString(":/res/shoot.wav"));
    ticksAfterLastShoot = 0;
}

QDebug operator<<(QDebug debug, const ShootingActor *actor)
{
    QDebugStateSaver saver(debug);
    QPointF pos = actor->scenePos();
    debug.nospace() << "ShootingActor(health=" << actor->health << ", " <<
                       "pos=(" << pos.x() << "," << pos.y() << "))";
    return debug;
}
