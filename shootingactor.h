#ifndef SHOOTINGACTOR_H
#define SHOOTINGACTOR_H

#include <QGraphicsScene>

#include "actor.h"
#include "projectile.h"

class ShootingActor : virtual public Actor
{
protected:
    int ticksPerShoot;
    int ticksAfterLastShoot;
    float projectileSpeed;
    std::vector<Projectile*> projectiles;
public:
    ShootingActor(QPixmap pm, int tps=10, float ps=6) : Actor(pm) {
        ticksPerShoot = tps;
        ticksAfterLastShoot = tps;
        projectileSpeed = ps;
        setFlag(QGraphicsItem::ItemIsFocusable);
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
        QPointF pos = mapToParent(QPointF(planeRect.width()/2-projectileRect.width()/2, 0));
        p->setPos(pos);

        p->setTransform(p->transform().rotate(transformRotation));

        projectiles.push_back(p);
        scene()->addItem(p);

        ticksAfterLastShoot = 0;
    }

    virtual bool wantToShoot() = 0;
};

#endif // SHOOTINGACTOR_H
