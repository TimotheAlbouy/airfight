#ifndef ACTOR_H
#define ACTOR_H

#include <QGraphicsPixmapItem>
#include <QDebug>

class Actor : public QGraphicsPixmapItem
{
public:
    Actor(QPixmap map) : QGraphicsPixmapItem(map) { };
    virtual void tick() = 0;
};

#endif // ACTOR_H
