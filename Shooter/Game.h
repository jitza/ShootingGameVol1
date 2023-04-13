//Jenny Itza and Alex Guerra
//Assignment 4
//GUI

#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QMediaPlayer>
#include <QAudioOutput>
#include "Player.h"
#include "Score.h"
#include "Health.h"


class Game: public QGraphicsView
{
    Q_OBJECT
public:
    Game(QWidget * parent=0);

    QGraphicsScene * scene;
    Player * player;
    Score * score;
    Health * health;

    QMediaPlayer * music;

public slots:
    void newGame();
};

#endif // GAME_H
