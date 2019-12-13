#ifndef ENEMYPLANE_H
#define ENEMYPLANE_H

#include "plane.h"
#include "playerplane.h"

/**
 * @brief A type of plane controlled by an AI trying to kill the player.
 */
class EnemyPlane : public Plane
{
protected:
    /**
     * @brief The player's pointer.
     */
    PlayerPlane *player;

    /**
     * @brief The rectangle defining the left field of view of the plane.
     */
    QGraphicsPolygonItem *leftSight;

    /**
     * @brief The rectangle defining the right field of view of the plane.
     */
    QGraphicsPolygonItem *rightSight;

    /**
     * @brief The rectangle defining the firing line of the plane.
     */
    QGraphicsRectItem *firingLine;

public:
    /**
     * @brief Constructor.
     * @param p the player's reference
     */
    EnemyPlane(PlayerPlane *p);

    /**
     * @brief Tell if the plane wants to turn right.
     * @return true iff the player is in the right sight triangle.
     */
    bool wantToTurnRight();

    /**
     * @brief Tell if the plane wants to turn left.
     * @return true iff the player is in the left sight triangle.
     */
    bool wantToTurnLeft();

    /**
     * @brief Tell if the plane wants to shoot.
     * @return true iff the player is in the firing line.
     */
    bool wantToShoot();

    /**
     * @brief Remove the plane from the scene and increment the player's score.
     */
    void die();

    /**
     * @brief Allow to serialize the plane for the debug stream.
     * @param debug the debug stream
     * @param plane the plane
     * @return the debug stream appended with the plane info
     */
    friend QDebug operator<<(QDebug debug, const EnemyPlane *plane);
};

#endif // ENEMYPLANE_H
