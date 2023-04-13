//Jenny Itza and Alex Guerra
//Assignment 4
//GUI

#include "Health.h"

Health::Health()
{
    // initialize score with zero
    health = 3;

    //draw score
    setPlainText(QString("Health: %1").arg(health));

    // set font color
    setDefaultTextColor(Qt::red);

    setFont(QFont("times", 16));
}

void Health::decrease()
{
    health--;
    setPlainText(QString("Health: %1").arg(health));
}

int Health::getHealth()
{
    return health;
}
