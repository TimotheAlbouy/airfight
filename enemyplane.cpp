#include "enemyplane.h"

void EnemyPlane::move()
{
    setTransform(transform().translate(0, -movingSpeed));
}
