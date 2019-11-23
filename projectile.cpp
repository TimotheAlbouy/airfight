#include "projectile.h"

void Projectile::move()
{
    QTransform t = Actor::transform();
    //t.translate(-movingSpeed, 0);
    setTransform(t);
}
