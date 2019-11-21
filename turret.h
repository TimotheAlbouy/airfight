#ifndef TURRET_H
#define TURRET_H

#include "shootingactor.h"

class Turret : public ShootingActor
{
public:
    Turret(QPixmap map);
    void shoot();
};

#endif // TURRET_H
