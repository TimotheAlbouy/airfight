#ifndef PLANE_H
#define PLANE_H

#include <QMovie>
#include <QLabel>

#include "movingactor.h"
#include "shootingactor.h"

class Plane : public MovingActor, public ShootingActor
{
public:
    Plane(QPixmap pm, float ss, unsigned int h, float ms) :
        Actor(pm, ss, h), MovingActor(pm, ss, h, ms), ShootingActor(pm, ss, h, 10, 5) { }

    void tick()
    {
        ShootingActor::tick();
        MovingActor::tick();
    }

    void handleOutOfBounds()
    {
        transformRotate(180);
    }

    void die()
    {
        QMovie *explosionGif = new QMovie(":/res/explosion.gif");
        QLabel *explosionLabel = new QLabel;
        QPointF center = mapToScene(boundingRect().center());
        QRectF labelRect(center);

        explosionLabel->setAttribute(Qt::WA_TranslucentBackground, true);
        explosionLabel->setMovie(explosionGif);
        //explosionLabel->setGeometry(labelRect);
        scene()->addWidget(explosionLabel);
        explosionGif->start();

        MovingActor::die();
    }
};

#endif // PLANE_H
