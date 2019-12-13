#ifndef PLAYERPLANE_H
#define PLAYERPLANE_H

#include "plane.h"

/**
 * @brief A type of plane controlled by the player.
 */
class PlayerPlane : public Plane
{
private:
    /**
     * @brief Indicator if the left arrow key is pressed on the keyboard.
     */
    bool leftPressed = false;

    /**
     * @brief Indicator if the right arrow key is pressed on the keyboard.
     */
    bool rightPressed = false;

    /**
     * @brief Indicator if the up arrow key is pressed on the keyboard.
     */
    bool upPressed = false;

    /**
     * @brief The score of the player, i.e. the number of enemies killed.
     */
    unsigned int score = 0;

    /**
     * @brief The display zone on the bottom left of the screen
     * showing the player's health and score.
     */
    QGraphicsSimpleTextItem *infoDisplay;

public:
    /**
     * @brief Constructor.
     * @param id the info display zone pointer
     */
    PlayerPlane(QGraphicsSimpleTextItem *id);

    /**
     * @brief Function called when a key is pressed.
     * @param event the key event
     */
    void keyPressEvent(QKeyEvent *event);

    /**
     * @brief Function called when a key is released.
     * @param event the key event
     */
    void keyReleaseEvent(QKeyEvent *event);

    /**
     * @brief Tell if the plane wants to turn right.
     * @return true iff the right arrow key is pressed.
     */
    bool wantToTurnRight();

    /**
     * @brief Tell if the plane wants to turn left.
     * @return true iff the left arrow key is pressed.
     */
    bool wantToTurnLeft();

    /**
     * @brief Tell if the plane wants to shoot.
     * @return true iff the up arrow key is pressed.
     */
    bool wantToShoot();

    /**
     * @brief Raise the player's score by 1.
     */
    void raiseScore();

    /**
     * @brief Update the information display.
     */
    void updateInfo();

    /**
     * @brief Lose health and update info.
     */
    void loseHealth();

    /**
     * @brief Gain health and update info.
     */
    void gainHealth();

    /**
     * @brief Allow to serialize the plane for the debug stream.
     * @param debug the debug stream
     * @param plane the plane
     * @return the debug stream appended with the plane info
     */
    friend QDebug operator<<(QDebug debug, const PlayerPlane *plane);
};

#endif // PLAYERPLANE_H
