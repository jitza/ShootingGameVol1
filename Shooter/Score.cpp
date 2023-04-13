//Jenny Itza and Alex Guerra
//Assignment 4
//GUI

#include "Score.h"

Score::Score()
{
    // initialize score with zero
    score = 0;

    //draw score
    setPlainText(QString("Score: %1").arg(score));

    // set font color
    setDefaultTextColor(Qt::blue);

    setFont(QFont("times", 16));
}

void Score::increase()
{
    score++;
    setPlainText(QString("Score: %1").arg(score));
}

int Score::getScore()
{
    return score;
}
