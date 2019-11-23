#ifndef ACTOR_H
#define ACTOR_H

#include <QGraphicsPixmapItem>


class Actor : public QGraphicsPixmapItem
{
public:
    Actor(QPixmap pm) : QGraphicsPixmapItem(pm) { }
    virtual void tick() = 0;
};

#endif // ACTOR_H
