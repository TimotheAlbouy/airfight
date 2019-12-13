#ifndef PLANE_H
#define PLANE_H

#include <QMovie>

#include "movingactor.h"
#include "shootingactor.h"

/**
 * @brief A plane actor, that can both move and shoot.
 */
class Plane : public MovingActor, public ShootingActor
{
protected:
    /**
     * @brief The gif of an explosion displayed when the plane dies.
     */
    QMovie *explosionGif = new QMovie(":/res/explosion.gif");

public:
    /**
     * @brief Constructor.
     * @param pm the pixmap of the plane
     * @param ss the steering speed of the plane
     * @param h the health of the plane
     * @param ms the moving speed of the plane
     */
    Plane(QPixmap pm, float ss, unsigned int h, float ms);

    /**
     * @brief Execute actions for every frame of the game.
     */
    void tick();

    /**
     * @brief Make the plane do a 180 degrees turn when it is out of bounds.
     */
    void handleOutOfBounds();

    /**
     * @brief Allow to serialize the plane for the debug stream.
     * @param debug the debug stream
     * @param plane the plane
     * @return the debug stream appended with the plane info
     */
    friend QDebug operator<<(QDebug debug, const Plane *plane);
};

#endif // PLANE_H
