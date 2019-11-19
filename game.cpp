#include <QTimer>

#include "game.h"
#include "plane.h"

Game::Game()
{
    timer = new QTimer(this);

    connect(timer, SIGNAL(timeout()), this, SLOT(tick()));

    QPixmap pixmap1(":/res/plane1.png");
    pixmap1.scaled(QSize(64, 64));
    player = new Plane(pixmap1);
    this->addItem(player);

    timer->start(1000);
}

/*
Game::initialize() {
    //
}

Game::run() {
    //
}*/

void Game::tick() {
    //
}
