#ifndef SHOOTINGACTOR_H
#define SHOOTINGACTOR_H

#include <QDebug>

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
        if (wantToShoot() && ticksAfterLastShoot >= ticksPerShoot)
            shoot();
        ticksAfterLastShoot++;
    }

    void shoot() {
        QPixmap projectilePm(":/res/projectile.png");
        projectilePm = projectilePm.scaled(10, 10, Qt::KeepAspectRatio);
        Projectile *p = new Projectile(projectilePm, this);

        QPointF pos = scenePos();
        //QRectF rect = boundingRect();
        p->setPos(pos.x(), y());

        projectiles.push_back(p);
        scene()->addItem(p);

        ticksAfterLastShoot = 0;
    }

    virtual bool wantToShoot() = 0;
};

#endif // SHOOTINGACTOR_H
