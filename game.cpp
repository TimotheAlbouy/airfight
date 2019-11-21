#include <QTimer>

#include "game.h"
#include "playerplane.h"
#include <QDebug>

Game::Game()
{
    timer = new QTimer(this);

    connect(timer, SIGNAL(timeout()), this, SLOT(tick()));

    QPixmap playerMap(":/res/player-plane.png");
    //QPixmap playerMap(":/res/black-box.png");
    playerMap.scaled(QSize(64, 64));
    player = new PlayerPlane(playerMap);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    this->addItem(player);

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
    player->tick();
}

void Game::setPlayerFocus() {
    player->setFocus();
}
