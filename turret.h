#ifndef TURRET_H
#define TURRET_H

#include "shootingactor.h"

class Turret : public ShootingActor
{
public:
    Turret(QPixmap pm) : Actor(pm), ShootingActor(pm) { }
    bool wantToShoot();
};

#endif // TURRET_H
