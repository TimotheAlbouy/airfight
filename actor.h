#ifndef ACTOR_H
#define ACTOR_H

#include <QGraphicsPixmapItem>


class Actor : public QGraphicsPixmapItem
{
protected:
    qreal transformRotation = 0;
    float steeringSpeed;
public:
    Actor(QPixmap pm, float ss=1.5) : QGraphicsPixmapItem(pm) {
        steeringSpeed = ss;
    }

    virtual void tick() {
        if (wantToTurnRight())
            turnRight();
        if (wantToTurnLeft())
            turnLeft();
    }

    void turnRight() {
        transformRotate(steeringSpeed);
    }

    void turnLeft() {
        transformRotate(-steeringSpeed);
    }

    void transformRotate(int rot) {
        QRectF rect = boundingRect();
        setTransform(transform()
            .translate(rect.width()/2, rect.height()/2)
            .rotate(rot)
            .translate(-rect.width()/2, -rect.height()/2)
        );
        transformRotation += rot;
    }

    virtual bool wantToTurnRight() = 0;
    virtual bool wantToTurnLeft() = 0;
};

#endif // ACTOR_H
