#ifndef SHOOTINGACTOR_H
#define SHOOTINGACTOR_H

#include <QGraphicsScene>

#include "actor.h"
#include "projectile.h"

/**
 * @brief A type of actor that can shoot.
 */
class ShootingActor : virtual public Actor
{
protected:
    /**
     * @brief The number
     */
    unsigned int ticksPerShoot;
    unsigned int ticksAfterLastShoot;
    float projectileSpeed;
public:
    /**
     * @brief Constructor.
     * @param pm the pixmap of the actor
     * @param ss the steering speed of the actor
     * @param h the initial health of the actor
     * @param dg the dying gif of the actor
     * @param gw the dying gif's width
     * @param gh the dying gif's height
     * @param tps the number of ticks between 2 shots
     * @param ps the projectile speed.
     */
    ShootingActor(unsigned int tps, float ps);

    /**
     * @brief Execute actions for every frame of the game.
     */
    void tick();

    /**
     * @brief Create a new projectile initiated by the actor.
     */
    void shoot();

    /**
     * @brief Tell if the actor wants to shoot.
     * @return true iff the actor wants to shoot
     */
    virtual bool wantToShoot() = 0;

    /**
     * @brief Allow to serialize the actor for the debug stream.
     * @param debug the debug stream
     * @param actor the actor
     * @return the debug stream appended with the actor info
     */
    friend QDebug operator<<(QDebug debug, const ShootingActor *actor);
};

#endif // SHOOTINGACTOR_H
