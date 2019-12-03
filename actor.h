#ifndef ACTOR_H
#define ACTOR_H

#include <QGraphicsPixmapItem>


class Actor : public QGraphicsPixmapItem
{
protected:
    qreal transformRotation = 0;
    float steeringSpeed;
    unsigned int health;
public:
    Actor(QPixmap pm, float ss, unsigned int h) : QGraphicsPixmapItem(pm)
    {
        steeringSpeed = ss;
        if (h == 0)
            h = 1;
        health = h;
    }

    virtual void tick()
    {
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

    void transformRotate(float rot) {
        QRectF rect = boundingRect();
        QTransform trsf;
        trsf.translate(rect.width()/2, rect.height()/2)
            .rotate(rot)
            .translate(-rect.width()/2, -rect.height()/2);
        setTransform(trsf, true);
        transformRotation += rot;
    }

    void loseHealth() {
        health--;
        if (health == 0)
            die();
    }

    virtual void die() {
        //qDebug() << this << " died";
        scene()->removeItem(this);
        //delete this;
    }

    virtual bool wantToTurnRight() = 0;
    virtual bool wantToTurnLeft() = 0;
};

#endif // ACTOR_H
