#ifndef MOVINGACTOR_H
#define MOVINGACTOR_H

#include <QGraphicsScene>
#include <QGraphicsView>

#include "actor.h"

/**
 * @brief A type of actor that can move.
 */
class MovingActor : virtual public Actor
{
protected:
    /**
     * @brief The speed (in pixels/tick) of translation of the actor.
     */
    float movingSpeed;

public:
    /**
     * @brief Constructor.
     * @param pm the pixmap of the actor
     * @param ss the steering speed of the actor
     * @param h the health of the actor
     * @param dg the dying gif of the actor
     * @param gw the dying gif's width
     * @param gh the dying gif's height
     * @param ms the moving speed of the actor
     */
    MovingActor(float ms);

    /**
     * @brief Execute actions for every frame of the game.
     */
    void tick();

    /**
     * @brief Tell if the actor is out of the bounds of the game.
     * @return true iff the actor is out of the bounds
     */
    bool isOutOfBounds();

    /**
     * @brief Move the actor forward.
     */
    void move();

    /**
     * @brief Handle the case when the actor is out of the bounds.
     */
    virtual void handleOutOfBounds() = 0;

    /**
     * @brief Allow to serialize the actor for the debug stream.
     * @param debug the debug stream
     * @param actor the actor
     * @return the debug stream appended with the actor info
     */
    friend QDebug operator<<(QDebug debug, const MovingActor *actor);
};

#endif // MOVINGACTOR_H
