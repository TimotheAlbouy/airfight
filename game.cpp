#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QTimer>

#include "game.h"
#include "playerplane.h"
#include "enemyplane.h"

Game::Game()
{
    // create the view
    const unsigned int width = 1000;
    const unsigned int height = 1000;
    QPixmap background(":/res/background.png");
    QGraphicsView *view = new QGraphicsView(this);
    view->setFixedSize(width, height);
    /* */
    view->setSceneRect(0, 0, width, height);
    view->fitInView(0, 0, width, height, Qt::KeepAspectRatio);
    /* */
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setBackgroundBrush(background);
    view->show();

    // create the player plane
    QPixmap playerPm(":/res/player-plane.png");
    playerPm = playerPm.scaled(128, 128, Qt::KeepAspectRatio);
    player = new PlayerPlane(playerPm, 1.99, 5, 6);
    player->setFocus();
    setStickyFocus(true);
    //player->setPos(0, 0);
    this->addItem(player);

    // create the enemy planes
    QPixmap enemyPm(":/res/enemy-plane.png");
    enemyPm = enemyPm.scaled(128, 128, Qt::KeepAspectRatio);
    //std::random_device rd;
    //std::mt19937 rng(rd());
    //std::uniform_int_distribution<int> uniWidth(-width/2,max);
    for (int i = 0; i < 1; i++) {
        EnemyPlane *enemy = new EnemyPlane(enemyPm, 1.5, 5, 5, player);
        //QTransform t(gen.bounded());
        enemy->setPos(250, 250);
        this->addItem(enemy);
    }

    // connect and start the timer
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(tick()));
    timer->start(25);
}

void Game::tick() {
    for (QGraphicsItem *item : items()) {
        if (Actor *actor = dynamic_cast<Actor*>(item))
            actor->tick();
    }
    handleCollisions();
}

void Game::handleCollisions() {
    QList<Actor*> collidingActorsListGlobal;

    for (QGraphicsItem *item : items()) {
        Actor *actor = dynamic_cast<Actor*>(item);

        // if the item is not an Actor, pass
        if (!actor)
            continue;

        QList<QGraphicsItem*> collidingItemsList = collidingItems(actor);
        QList<Actor*> collidingActorsList;

        for (QGraphicsItem *collidingItem : collidingItemsList) {
            Actor *collidingActor = dynamic_cast<Actor*>(collidingItem);

            // if the colliding item is not an Actor, pass
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

    for (Actor *collidingActor : collidingActorsListGlobal)
        collidingActor->loseHealth();
}

