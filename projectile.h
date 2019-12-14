#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "movingactor.h"

class ShootingActor; // forward declaration to prevent circular dependency

/**
 * @brief A projectile shot by a shooting actor.
 */
class Projectile : public MovingActor
{
protected:
    /**
     * @brief The shooter of the projectile.
     */
    ShootingActor *shooter;

public:
    /**
     * @brief Constructor.
     * @param s the shooter of the projectile
     */
    Projectile(ShootingActor *s);

    /**
     * @brief Never want to turn right, return always false.
     */
    bool wantToTurnRight();

    /**
     * @brief Never want to turn left, return always false.
     */
    bool wantToTurnLeft();

    /**
     * @brief Die when the projectile is out of bounds.
     */
    void handleOutOfBounds();

    /**
     * @brief Allow to serialize the projectile for the debug stream.
     * @param debug the debug stream
     * @param projectile the projectile
     * @return the debug stream appended with the projectile info
     */
    friend QDebug operator<<(QDebug debug, const Projectile *projectile);
};

#endif // PROJECTILE_H
