//Jenny Itza and Alex Guerra
//Assignment 4
//GUI

#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>
#include <QFont>

class Score : public QGraphicsTextItem
{
public:
    Score();
    void increase();
    int getScore();
private:
    int score;
};

#endif // SCORE_H
