//Jenny Itza and Alex Guerra
//Assignment 4
//GUI

#include "Game.h"
#include <QTimer>
#include <QFont>
#include "Enemy.h"


extern Game * game;

Game::Game(QWidget *parent){
    // create the scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600); // make the scene 800x600 instead of infinity by infinity (default)
    setBackgroundBrush(QBrush(QImage(":/images/images/bg.png")));


    // make the newly created scene the scene to visualize (since Game is a QGraphicsView Widget,
    // it can be used to visualize scenes)
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);

    // create the player
    player = new Player();
    player->pixmap(); // change the rect from 0x0 (default) to 100x100 pixels
    player->setPos(400,500); // TODO generalize to always be in the middle bottom of screen
    // make the player focusable and set it to be the current focus
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    // add the player to the scene
    scene->addItem(player);

    //create score
    score = new Score();
    scene->addItem(score);

    //create Health
    health = new Health();
    health->setPos(health->x(), health->y()+25);
    scene->addItem(health);

    // spawn enemies
    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    timer->start(2000);

    show();

    //play music
    music = new QMediaPlayer();
    music->setAudioOutput(new QAudioOutput());
    music->setSource(QUrl("qrc:/sounds/sound/bgsound.mp3"));
    music->play();
}

void Game::newGame()
{
        game->close();
        game = new Game();

}
