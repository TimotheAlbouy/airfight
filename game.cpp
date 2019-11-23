#include <QTimer>

#include "game.h"
#include "playerplane.h"
#include "enemyplane.h"

Game::Game()
{
    timer = new QTimer(this);

    connect(timer, SIGNAL(timeout()), this, SLOT(tick()));

    QPixmap playerPm(":/res/player-plane.png");
    //QPixmap playerMap(":/res/black-box.png");
    playerPm = playerPm.scaled(128, 128, Qt::KeepAspectRatio);
    player = new PlayerPlane(playerPm);
    player->setPos(0, 0);

    this->addItem(player);
    actors.push_back(player);

    QPixmap enemyPm(":/res/black-box.png");
    enemyPm = enemyPm.scaled(64, 64, Qt::KeepAspectRatio);
    for (int i = 0; i < 3; i++) {
        //EnemyPlane *enemy = new EnemyPlane(enemyPm);
        //this->addItem(enemy);
        //actors.push_back(enemy);
    }

    timer->start(25);
}

void Game::tick() {
    for (Actor *actor : actors)
        actor->tick();
}

void Game::setPlayerFocus() {
    player->setFocus();
}
