//Jenny Itza and Alex Guerra
//Assignment 4
//GUI

#include "Player.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "Bullet.h"
#include "Enemy.h"

Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    bulletsound = new QMediaPlayer();
    bulletsound->setAudioOutput(new QAudioOutput());
    bulletsound->setSource(QUrl("qrc:/sounds/sound/bullet.wav"));

    //draw player
    setPixmap(QPixmap(":/images/images/player.png"));

}

void Player::keyPressEvent(QKeyEvent *event){
    // move the player left and right
    if (event->key() == Qt::Key_Left){
        if (pos().x() > 0)
        setPos(x()-10,y());
    }
    else if (event->key() == Qt::Key_Right){
        if (pos().x() + 100 < 800)
        setPos(x()+10,y());
    }
    // shoot with the spacebar
    else if (event->key() == Qt::Key_Space){
        // create a bullet
        Bullet * bullet = new Bullet();
        bullet->setPos(x(),y());
        scene()->addItem(bullet);

        //play bullet sound
        if(bulletsound->playbackState() == QMediaPlayer::PlayingState)
        {
            bulletsound->setPosition(0);
        }
        else if(bulletsound->playbackState() == QMediaPlayer::StoppedState)
        {
            bulletsound->play();
        }
    }
}

void Player::spawn(){
    // create an enemy
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);
}
