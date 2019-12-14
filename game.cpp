#include <QDebug>
#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QGraphicsProxyWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QMediaPlaylist>
#include <QMediaPlayer>

#include "game.h"
#include "playerplane.h"
#include "enemyplane.h"

Game::Game()
{
    // create the view
    view = new QGraphicsView(this);
    view->setFixedSize(WIDTH, HEIGHT);
    setSceneRect(0, 0, WIDTH, HEIGHT);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->show();

    // create and connect the timer
    timer = new QTimer(this);
    timer->setInterval(25);
    connect(timer, SIGNAL(timeout()), this, SLOT(tick()));

    // create the widgets
    createGameOverWidget();
    createMenuWidget();
    createPauseWidgets();

    // create the backgrounds
    gameBackground = QPixmap(":/res/game-background.png");
    menuBackground = QPixmap(":/res/menu-background.jpg");
    if (!gameBackground || !menuBackground)
        throw QString("Background images not found");
    menuBackground = menuBackground.scaled(WIDTH, HEIGHT, Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation);

    // create the info display
    infoDisplay = new QGraphicsSimpleTextItem();
    infoDisplay->setPos(10, HEIGHT-60);
    infoDisplay->setZValue(10);
    addItem(infoDisplay);

    // create the logo
    logo = new QGraphicsPixmapItem(QPixmap(":/res/logo.png"));
    logo->setPos(WIDTH/3.5, HEIGHT/50);
    logo->setZValue(10);
    addItem(logo);

    // play the background music in a loop
    QMediaPlaylist *playlist = new QMediaPlaylist();
    playlist->addMedia(QUrl("qrc:/res/music.mp3"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);
    QMediaPlayer *music = new QMediaPlayer();
    music->setPlaylist(playlist);
    music->play();

    // do not lose focus on clicks
    setStickyFocus(true);

    startMenu();
}

void Game::createGameOverWidget()
{
    // create the replay and exit buttons
    QPushButton *replayButton = new QPushButton("Replay");
    QPushButton *exitButton = new QPushButton("Exit");

    // connect the buttons to their respective action
    connect(replayButton, SIGNAL(released()), this, SLOT(startGame()));
    connect(exitButton, SIGNAL(released()), this, SLOT(startMenu()));

    // add the buttons to the inner widget
    QWidget *widget = new QWidget;
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(replayButton);
    layout->addWidget(exitButton);
    widget->setLayout(layout);

    // create the game over widget
    gameOverWidget = addWidget(widget);
    gameOverWidget->setZValue(10);
    gameOverWidget->setPos(WIDTH/2, HEIGHT/2);
}

void Game::createMenuWidget()
{
    // create the play and help buttons
    QPushButton *playButton = new QPushButton("Play");
    QPushButton *exitButton = new QPushButton("Exit");

    // connect the buttons to their respective action
    connect(playButton, SIGNAL(released()), this, SLOT(startGame()));
    connect(exitButton, SIGNAL(released()), this, SLOT(exitGame()));

    // add the buttons to the inner widget
    QWidget *widget = new QWidget;
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(playButton);
    layout->addWidget(exitButton);
    widget->setLayout(layout);

    // create the menu widget
    menuWidget = addWidget(widget);
    menuWidget->setZValue(10);
    menuWidget->setPos(WIDTH/4, HEIGHT/2);
}

void Game::createPauseWidgets()
{
    // create the resume and exit buttons
    QPushButton *pauseInnerButton = new QPushButton("Pause");
    QPushButton *resumeButton = new QPushButton("Resume");
    QPushButton *exitButton = new QPushButton("Exit");

    // connect the buttons to their respective action
    connect(pauseInnerButton, SIGNAL(released()), this, SLOT(pauseGame()));
    connect(resumeButton, SIGNAL(released()), this, SLOT(resumeGame()));
    connect(exitButton, SIGNAL(released()), this, SLOT(startMenu()));

    // add the buttons of the inner widgets
    QWidget *widget1 = new QWidget;
    pauseInnerButton->setParent(widget1);
    QWidget *widget2 = new QWidget;
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(resumeButton);
    layout->addWidget(exitButton);
    widget2->setLayout(layout);

    // create the pause widgets
    pauseButton = addWidget(widget1);
    pauseButton->setZValue(10);
    pauseButton->setPos(WIDTH-100, HEIGHT-50);
    pauseWidget = addWidget(widget2);
    pauseWidget->setZValue(10);
    pauseWidget->setPos(WIDTH/2, HEIGHT/2);
}

void Game::createPlayer()
{
    player = new PlayerPlane(infoDisplay);
    player->setPos(WIDTH/2, HEIGHT/2);
    this->addItem(player);
}

void Game::randomDrawSpawnEnemy()
{
    int randomDraw = randInt(0, MAX_DRAW);
    if (randomDraw == MAX_DRAW)
        spawnEnemy();
}

void Game::handleCollisions()
{
    // create a global list for the colliding actors of the scene
    QList<Actor*> collidingActorsListGlobal;

    for (QGraphicsItem *item : items()) {
        // if the item is not an actor, pass
        Actor *actor = dynamic_cast<Actor*>(item);
        if (!actor)
            continue;

        // retrieve all the colliding items of the given actor
        QList<QGraphicsItem*> collidingItemsList = collidingItems(actor);
        // create a local list for the colliding actors of the given actor
        QList<Actor*> collidingActorsList;

        for (QGraphicsItem *collidingItem : collidingItemsList) {
            // if the colliding item is not an actor, pass
            Actor *collidingActor = dynamic_cast<Actor*>(collidingItem);
            if (!collidingActor)
                continue;
            // if the actor is already in the list, pass
            if (collidingActorsListGlobal.indexOf(collidingActor) != -1)
                continue;
            // add the colliding actor to the local list
            collidingActorsList.append(collidingActor);
        }

        if (!collidingActorsList.empty()) {
            // add the local list to the global list
            collidingActorsListGlobal.append(collidingActorsList);
            // if the actor is not already in the list, add it
            if (collidingActorsListGlobal.indexOf(actor) == -1)
                collidingActorsListGlobal.append(actor);
        }
    }

    // every colliding actor loses health
    for (Actor *collidingActor : collidingActorsListGlobal)
        collidingActor->loseHealth();
}

void Game::spawnEnemy()
{
    EnemyPlane *enemy = new EnemyPlane(player);
    QRectF enemyRect = enemy->boundingRect();

    int direction = randInt(0, 3);
    int rot = 0;
    QPointF pos;
    switch (direction) {
        case 0: // arrive from the left edge
            rot = 90;
            pos = QPointF(-enemyRect.height(), randInt(0, HEIGHT-enemyRect.width()));
            break;
        case 1: // arrive from the upper edge
            rot = 180;
            pos = QPointF(randInt(enemyRect.width(), HEIGHT), 0);
            break;
        case 2: // arrive from the right edge
            rot = -90;
            pos = QPointF(WIDTH, randInt(enemyRect.width(), HEIGHT));
            break;
        case 3: // arrive from the lowest edge
            pos = QPointF(randInt(0, WIDTH-enemyRect.width()), HEIGHT);
            break;
    }

    enemy->transformRotate(rot);
    enemy->setPos(pos);
    this->addItem(enemy);
}

void Game::clearActors()
{
    for (QGraphicsItem *item : items()) {
        if (Actor *actor = dynamic_cast<Actor*>(item))
            removeItem(actor);
    }
}

int Game::randInt(int min, int max)
{
    if (!rngSeeded) {
        std::random_device rd;
        rng = std::mt19937(rd());
        rngSeeded = true;
    }
    std::uniform_int_distribution<int> uniDist(min, max);
    return uniDist(rng);
}

// SLOTS

void Game::tick()
{
    for (QGraphicsItem *item : items()) {
        if (Actor *actor = dynamic_cast<Actor*>(item))
            actor->tick();
    }
    randomDrawSpawnEnemy();
    handleCollisions();

    if (player->isDead()) {
        timer->stop();
        gameOverWidget->show();
    }
}

void Game::startGame()
{
    // set the game background
    view->setBackgroundBrush(gameBackground);

    // hide the proper widgets
    gameOverWidget->hide();
    gameOverWidget->clearFocus();
    menuWidget->hide();
    menuWidget->clearFocus();
    pauseWidget->hide();
    pauseWidget->clearFocus();

    // hide the logo
    logo->hide();

    // clear all the actors
    clearActors();

    // show the info display
    infoDisplay->show();

    // show the pause button
    pauseButton->show();
    pauseButton->clearFocus();

    // create the player plane
    createPlayer();

    // create a first enemy
    spawnEnemy();

    // start the timer
    timer->start();
}

void Game::startMenu()
{
    // set the menu background
    view->setBackgroundBrush(menuBackground);

    // hide the proper widgets
    gameOverWidget->hide();
    gameOverWidget->clearFocus();
    pauseWidget->hide();
    pauseWidget->clearFocus();
    pauseButton->hide();
    pauseButton->clearFocus();

    // hide the info display
    infoDisplay->hide();

    // clear all the actors
    clearActors();

    // show the menu widget
    menuWidget->show();

    // show the logo
    logo->show();
}

void Game::pauseGame()
{
    timer->stop();
    pauseWidget->show();
}

void Game::resumeGame()
{
    timer->start();
    pauseWidget->hide();

    // clear the focus of the widgets
    pauseWidget->clearFocus();
    pauseButton->clearFocus();
    gameOverWidget->clearFocus();
    menuWidget->clearFocus();
}

void Game::exitGame()
{
    QApplication::quit();
}

// OPERATOR OVERRIDE

QDebug operator<<(QDebug debug, const Game *game)
{
    QDebugStateSaver saver(debug);
    debug.nospace() << "Game(width=" << game->WIDTH << ", height=" << game->HEIGHT << ", items=(";

    for (QGraphicsItem *item : game->items()) {
        debug.nospace() << "\n\t";
        if (PlayerPlane *playerPlane = dynamic_cast<PlayerPlane*>(item))
            debug.nospace() << playerPlane;
        else if (EnemyPlane *enemyPlane = dynamic_cast<EnemyPlane*>(item))
            debug.nospace() << enemyPlane;
        else if (Projectile *projectile = dynamic_cast<Projectile*>(item))
            debug.nospace() << projectile;
        else if (ShootingActor *shootingActor = dynamic_cast<ShootingActor*>(item))
            debug.nospace() << shootingActor;
        else if (MovingActor *movingActor = dynamic_cast<MovingActor*>(item))
            debug.nospace() << movingActor;
        else if (Actor *actor = dynamic_cast<Actor*>(item))
            debug.nospace() << actor;
        else debug.nospace() << item;
    }

    debug.nospace() << "\n))";
    return debug;
}
