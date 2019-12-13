#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>

#include "playerplane.h"

/**
 * @brief Class managing the view and logic of the application.
 */
class Game : public QGraphicsScene
{
    Q_OBJECT
private:
    /**
     * @brief The width of the window.
     */
    static const int WIDTH = 1000;

    /**
     * @brief The height of the window.
     */
    static const int HEIGHT = 1000;

    /**
     * @brief The value for which a new enemy is spawned if it is randomly drawn.
     */
    static const int MAX_DRAW = 250;

    /**
     * @brief View of the application.
     */
    QGraphicsView *view;

    /**
     * @brief Timer for scheduling the game's frames.
     */
    QTimer *timer;

    /**
     * @brief Pointer to the player's plane.
     */
    PlayerPlane *player;

    /**
     * @brief Mersenne-Twister pseudo-random generator.
     */
    std::mt19937 rng;

    /**
     * @brief Indicator if the pseudo-random generator is seeded.
     */
    bool rngSeeded = false;

    /**
     * @brief The widget showing when the game is over.
     */
    QGraphicsProxyWidget *gameOverWidget;

    /**
     * @brief The widget showing on the main menu.
     */
    QGraphicsProxyWidget *menuWidget;

    /**
     * @brief The widget showing when the game is paused.
     */
    QGraphicsProxyWidget *pauseWidget;

    /**
     * @brief The button to pause the game.
     */
    QGraphicsProxyWidget *pauseButton;

    /**
     * @brief The display zone on the bottom left of the screen
     * showing the player's health and score.
     */
    QGraphicsSimpleTextItem *infoDisplay;

    /**
     * @brief Logo image displayed on the main menu.
     */
    QGraphicsPixmapItem *logo;

    /**
     * @brief The background image of the game.
     */
    QPixmap gameBackground;

    /**
     * @brief The background image of the menu.
     */
    QPixmap menuBackground;

public:
    /**
     * @brief Constructor.
     */
    Game();

    /**
     * @brief Create the game over widget.
     */
    void createGameOverWidget();

    /**
     * @brief Create the menu widget.
     */
    void createMenuWidget();

    /**
     * @brief Create the pause widget and the pause button.
     */
    void createPauseWidgets();

    /**
     * @brief Create the player plane on the scene.
     */
    void createPlayer();

    /**
     * @brief Make all the actors currently colliding in the scene lose health.
     */
    void handleCollisions();

    /**
     * @brief Call spawnEnemy() only if the random integer drawn is equal to MAX_DRAW.
     */
    void randomDrawSpawnEnemy();

    /**
     * @brief Spawn an enemy randomly positioned in the scene.
     */
    void spawnEnemy();

    /**
     * @brief Clear the list of actors of the scene.
     */
    void clearActors();

    /**
     * @brief Generate a pseudo-random integer using a Mersenne Twister generator.
     * @param min the minimum bound
     * @param max the maximum bound
     * @return a pseudo-randomly generated integer
     */
    int randInt(int min, int max);

    /**
     * @brief Allow to serialize the game for the debug stream.
     * @param debug the debug stream
     * @param game the game
     * @return the debug stream appended with the game info
     */
    friend QDebug operator<<(QDebug debug, const Game *game);

public slots:
    /**
     * @brief Refresh the scene when the timer emits a timeout signal.
     */
    void tick();

    /**
     * @brief Start the game.
     */
    void startGame();

    /**
     * @brief Start the main menu.
     */
    void startMenu();

    /**
     * @brief Pause the game.
     */
    void pauseGame();

    /**
     * @brief Resume the game.
     */
    void resumeGame();
};

#endif // GAME_H
