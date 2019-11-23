#ifndef SHOOTINGACTOR_H
#define SHOOTINGACTOR_H

#include <QGraphicsScene>

#include "actor.h"
#include "projectile.h"

class ShootingActor : virtual public Actor
{
protected:
    int ticksPerShoot;
    int ticksAfterLastShoot = 0;
    float projectileSpeed;
    std::vector<Projectile*> projectiles;
public:
    ShootingActor(QPixmap pm, int tps=5, float ps=5) : Actor(pm) {
        ticksPerShoot = tps;
        projectileSpeed = ps;
    }
    void tick() {
        if (wantToShoot())
            shoot();
        ticksAfterLastShoot++;
    }
    void shoot() {
        if (ticksAfterLastShoot < ticksPerShoot) {
            QPixmap pm(":/res/projectile.png");
            Projectile *p = new Projectile(pm, this);
            scene()->addItem(p);
            ticksAfterLastShoot = 0;
        }
    }
    virtual bool wantToShoot() = 0;
};

#endif // SHOOTINGACTOR_H
