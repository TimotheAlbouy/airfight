#ifndef PLANE_H
#define PLANE_H

#include <QMovie>
#include <QLabel>

#include "movingactor.h"
#include "shootingactor.h"

class Plane : public QObject, public MovingActor, public ShootingActor
{
    Q_OBJECT
protected:
    QMovie *explosionGif = new QMovie(":/res/explosion.gif");
public:
    Plane(QPixmap pm, float ss, unsigned int h, float ms) :
        Actor(pm, ss, h), MovingActor(pm, ss, h, ms), ShootingActor(pm, ss, h, 10, 5)
    {
        connect(explosionGif, SIGNAL(frameChanged(int)), this, SLOT(stopExplosionGif()));
    }

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
        int gifWidth = 156;
        int gifHeight = 228;
        QLabel *explosionLabel = new QLabel;
        QPointF center = mapToScene(boundingRect().center());
        QRect labelRect(
            center.x()-gifWidth/2,
            center.y()-gifHeight/2,
            gifWidth,
            gifHeight
        );

        explosionLabel->setAttribute(Qt::WA_TranslucentBackground, true);
        explosionLabel->setMovie(explosionGif);
        explosionLabel->setGeometry(labelRect);
        scene()->addWidget(explosionLabel);
        explosionGif->start();

        MovingActor::die();
    }

public slots:
    void stopExplosionGif()
    {
        if (explosionGif->currentFrameNumber() == explosionGif->frameCount() - 1) {
            explosionGif->stop();
            explosionGif->deleteLater();
        }
    }
};

#endif // PLANE_H
