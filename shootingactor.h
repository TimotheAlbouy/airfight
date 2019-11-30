#ifndef SHOOTINGACTOR_H
#define SHOOTINGACTOR_H

#include <QGraphicsScene>

#include "actor.h"
#include "projectile.h"

class ShootingActor : virtual public Actor
{
protected:
    unsigned int ticksPerShoot;
    unsigned int ticksAfterLastShoot;
    float projectileSpeed;
public:
    ShootingActor(QPixmap pm, float ss, unsigned int h, unsigned int tps, float ps) :
            Actor(pm, ss, h)
    {
        ticksPerShoot = tps;
        ticksAfterLastShoot = tps;
        projectileSpeed = ps;
    }

    void tick() {
        Actor::tick();
        if (wantToShoot() && ticksAfterLastShoot >= ticksPerShoot)
            shoot();
        ticksAfterLastShoot++;
    }

    void shoot() {
        QPixmap projectilePm(":/res/red-box.png");
        projectilePm = projectilePm.scaled(10, 10, Qt::KeepAspectRatio);
        Projectile *p = new Projectile(projectilePm, this);

        QRectF planeRect = boundingRect();
        QRectF projectileRect = p->boundingRect();
        QPointF pos = mapToParent(
            QPointF(
                planeRect.width()/2-projectileRect.width()/2,
                -2*projectileRect.height()
            )
        );
        p->setPos(pos);
        p->transformRotate(transformRotation);

        scene()->addItem(p);
        ticksAfterLastShoot = 0;
    }

    virtual bool wantToShoot() = 0;
};

#endif // SHOOTINGACTOR_H
