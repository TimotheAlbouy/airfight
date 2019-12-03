#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QTimer>

#include "game.h"
#include "playerplane.h"
#include "enemyplane.h"

Game::Game()
{
    setStickyFocus(true);

    // create the view
    QPixmap background(":/res/background.png");
    QGraphicsView *view = new QGraphicsView(this);
    view->setFixedSize(WIDTH, HEIGHT);
    setSceneRect(0, 0, WIDTH, HEIGHT);
    //view->fitInView(0, 0, width, height, Qt::KeepAspectRatio);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setBackgroundBrush(background);
    view->show();

    // create the player plane
    QPixmap playerPm(":/res/player-plane.png");
    playerPm = playerPm.scaled(96, 96, Qt::KeepAspectRatio);
    player = new PlayerPlane(playerPm, 1.5, 5, 6);
    player->setPos(0, 0);
    this->addItem(player);

    // create the enemy planes
    for (int i = 0; i < 1; i++)
        spawnEnemy();

    // connect and start the timer
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(tick()));
    timer->start(25);
}

void Game::tick()
{
    for (QGraphicsItem *item : items()) {
        if (Actor *actor = dynamic_cast<Actor*>(item))
            actor->tick();
    }
    handleCollisions();
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
    QPixmap enemyPm(":/res/enemy-plane.png");
    enemyPm = enemyPm.scaled(96, 96, Qt::KeepAspectRatio);
    EnemyPlane *enemy = new EnemyPlane(enemyPm, 1, 5, 5, player);
    QPointF pos(randInt(0, WIDTH), randInt(0, HEIGHT));
    enemy->setPos(pos);
    this->addItem(enemy);
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
