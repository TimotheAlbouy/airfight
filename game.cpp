#include <QTimer>

#include "game.h"
#include "playerplane.h"
#include "enemyplane.h"
#include <QDebug>

Game::Game()
{
    timer = new QTimer(this);

    connect(timer, SIGNAL(timeout()), this, SLOT(tick()));

    QPixmap playerMap(":/res/player-plane.png");
    //QPixmap playerMap(":/res/black-box.png");
    playerMap = playerMap.scaled(128, 128, Qt::KeepAspectRatio);
    player = new PlayerPlane(playerMap);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    this->addItem(player);
    actors.push_back(player);

    QPixmap enemyMap(":/res/black-box.png");
    enemyMap = enemyMap.scaled(64, 64, Qt::KeepAspectRatio);
    for (int i = 0; i < 3; i++) {
        EnemyPlane *enemy = new EnemyPlane(enemyMap);
        //this->addItem(enemy);
        //actors.push_back(enemy);
    }

    timer->start(25);
}

/*
Game::initialize() {
    //
}

Game::run() {
    //
}*/

void Game::tick() {
    for (Actor *actor : actors)
        actor->tick();
}

void Game::setPlayerFocus() {
    player->setFocus();
}
