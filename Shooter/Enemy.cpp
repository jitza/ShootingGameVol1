#include "Enemy.h"
#include <QTimer>
#include <QGraphicsScene>
//Jenny Itza and Alex Guerra
//Assignment 4
//GUI

#include <QList>
#include <stdlib.h> // rand() -> really large int
#include "Game.h"

extern Game * game;

Enemy::Enemy(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    //set random x position
    int random_number = rand() % 700;
    setPos(random_number,0);

    // drew the enemy
    setPixmap(QPixmap(":/images/images/enemy.png"));

    setTransformOriginPoint(50, 50);
    setRotation(180);

    // make/connect a timer to move() the enemy every so often
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    // start the timer
    timer->start(50);
}

void Enemy::move(){
    // move enemy down
    setPos(x(),y()+5);

    // destroy enemy when it goes out of the screen
    if (pos().y() > 600)
    {
        game->health->decrease();
        scene()->removeItem(this);
        delete this;
    }
    if(game->health->getHealth() == 0)
    {
        game->scene->clear();
        game->music->stop();

        QLabel * gameOver = new QLabel();
        gameOver->setText("Game Over");
        gameOver->setFont(QFont("times",24));
        gameOver->setGeometry(310,120,220,50);
        gameOver->setStyleSheet(
                    "color: white;"
                    "background-color: rgba(255,255,255,0);"
                    );
        QPushButton * startOver = new QPushButton();
        startOver->setText("Start Over");
        startOver->setFont(QFont("times",12));
        startOver->setGeometry(320,230,150,50);
        startOver->setStyleSheet(
                    "color: white;"
                    "background-color: black;"
                    "border: 2px solid #73AD21;"
                    );
        QPushButton * quitGame = new QPushButton();
        quitGame->setText("Quit Over");
        quitGame->setFont(QFont("times",12));
        quitGame->setGeometry(320,290,150,50);
        quitGame->setStyleSheet(
                    "color: white;"
                    "background-color: black;"
                    "border: 2px solid #73AD21;"
                    );

        game->scene->addWidget(gameOver);
        game->scene->addWidget(startOver);
        game->scene->addWidget(quitGame);

        connect(quitGame, SIGNAL(clicked()), qApp, SLOT(quit()));
        connect(startOver, SIGNAL(clicked()), game, SLOT(newGame()));

    }
}
