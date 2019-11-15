#ifndef ACTOR_H
#define ACTOR_H

#include <QGraphicsItem>

class Actor : QGraphicsItem
{
private:
    int x;
    int y;
    int width;
    int height;
public:
    virtual void tick() = 0;
};

#endif // ACTOR_H
