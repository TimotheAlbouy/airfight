#include <QDebug>
#include <QLabel>
#include <QMovie>

#include "actor.h"

Actor::Actor(QPixmap pm, float ss, unsigned int h, QMovie *dg, unsigned int gw, unsigned int gh)
    : QGraphicsPixmapItem(pm)
{
    steeringSpeed = ss;
    if (h == 0)
        h = 1;
    health = h;

    if (dg != nullptr) {
        dyingGif = dg;
        gifWidth = gw;
        gifHeight = gh;
        connect(dyingGif, SIGNAL(frameChanged(int)), this, SLOT(stopDyingGif()));
    }
}

void Actor::tick()
{
    if (wantToTurnRight())
        turnRight();
    if (wantToTurnLeft())
        turnLeft();
}

void Actor::turnRight()
{
    transformRotate(steeringSpeed);
}

void Actor::turnLeft()
{
    transformRotate(-steeringSpeed);
}

void Actor::transformRotate(float rot)
{
    QRectF rect = boundingRect();
    QTransform trsf;
    trsf.translate(rect.width()/2, rect.height()/2)
        .rotate(rot)
        .translate(-rect.width()/2, -rect.height()/2);
    setTransform(trsf, true);
    transformRotation += rot;
}

bool Actor::isDead()
{
    return health <= 0;
}

void Actor::loseHealth()
{
    health--;
    if (health <= 0)
        die();
}

void Actor::gainHealth()
{
    health++;
}

void Actor::die() {
    if (dyingGif != nullptr) {
        QLabel *dyingLabel = new QLabel;
        QPointF center = mapToScene(boundingRect().center());
        QRect labelRect(
            center.x()-gifWidth/2,
            center.y()-gifHeight/2,
            gifWidth,
            gifHeight
        );
        dyingLabel->setAttribute(Qt::WA_TranslucentBackground, true);
        dyingLabel->setMovie(dyingGif);
        dyingLabel->setGeometry(labelRect);
        scene()->addWidget(dyingLabel);
        dyingGif->start();
    }

    scene()->removeItem(this);
}

// SLOTS

void Actor::stopDyingGif()
{
    if (dyingGif->currentFrameNumber() == dyingGif->frameCount() - 1) {
        dyingGif->stop();
        dyingGif->deleteLater();
    }
}

// OPERATOR OVERRIDE

QDebug operator<<(QDebug debug, const Actor *actor)
{
    QDebugStateSaver saver(debug);
    QPointF pos = actor->scenePos();
    debug.nospace() << "Actor(health=" << actor->health << ", pos=(" << pos.x() << "," << pos.y() << "))";
    return debug;
}
