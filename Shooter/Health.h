//Jenny Itza and Alex Guerra
//Assignment 4
//GUI

#ifndef HEALTH_H
#define HEALTH_H

#include <QGraphicsTextItem>
#include <QFont>

class Health : public QGraphicsTextItem
{
public:
    Health();
    void decrease();
    int getHealth();

private:
    int health;
};

#endif // HEALTH_H
