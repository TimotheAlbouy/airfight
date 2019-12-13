#ifndef ACTOR_H
#define ACTOR_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>

/**
 * @brief An actor of the game.
 */
class Actor : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
protected:
    /**
     * @brief A value to keep track of the transform's rotation,
     * as it is impossible to retrieve it using the transform's matrix.
     */
    qreal transformRotation = 0;

    /**
     * @brief The speed (in degrees/tick) of rotation of the actor.
     */
    float steeringSpeed;

    /**
     * @brief The number of health points of the actor.
     */
    unsigned int health;

    /**
     * @brief The gif played when the actor dies.
     */
    QMovie *dyingGif;

    /**
     * @brief The dying gif's width.
     */
    unsigned int gifWidth;

    /**
     * @brief The dying gif's height.
     */
    unsigned int gifHeight;

public:
    /**
     * @brief Constructor.
     * @param pm the pixmap of the actor
     * @param ss the steering speed of the actor
     * @param h the initial health of the actor
     * @param dg the dying gif of the actor
     * @param gw the dying gif's width
     * @param gh the dying gif's height
     */
    Actor(QPixmap pm, float ss, unsigned int h, QMovie *dg, unsigned int gw, unsigned int gh);

    /**
     * @brief Execute actions for every frame of the game.
     */
    virtual void tick();

    /**
     * @brief Turn the actor right.
     */
    void turnRight();

    /**
     * @brief Turn the actor left.
     */
    void turnLeft();

    /**
     * @brief Rotate the actor using its transform rather than the direct rotation.
     * @param rot the angle of rotation in degree (can be negative)
     */
    void transformRotate(float rot);

    /**
     * @brief Tell if the actor is dead.
     * @return true iff the actor is dead
     */
    bool isDead();

    /**
     * @brief Decrement the health of the actor by 1.
     */
    virtual void loseHealth();

    /**
     * @brief Increment the health of the actor by 1.
     */
    virtual void gainHealth();

    /**
     * @brief Remove the actor from the scene.
     */
    virtual void die();

    /**
     * @brief Tell if the actor wants to turn right.
     * @return true iff the actor wants to turn right
     */
    virtual bool wantToTurnRight() = 0;

    /**
     * @brief Tell if the actor wants to turn left
     * @return true iff the actor wants to turn left
     */
    virtual bool wantToTurnLeft() = 0;

   /**
    * @brief Allow to serialize the actor for the debug stream.
    * @param debug the debug stream
    * @param actor the actor
    * @return the debug stream appended with the actor info
    */
   friend QDebug operator<<(QDebug debug, const Actor *actor);

public slots:
   /**
    * @brief Stop the dying gif when it reached its last frame.
    */
   void stopDyingGif();
};

#endif // ACTOR_H
