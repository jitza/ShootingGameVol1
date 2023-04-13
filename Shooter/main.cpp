//Jenny Itza and Alex Guerra
//Assignment 4
//GUI

#include <QApplication>
#include <QIcon>
#include "Game.h"


Game * game;

int main(int argc, char *argv[]){
    QApplication a(argc, argv);

    //set application Image
    a.setWindowIcon(QIcon(":/images/images/player.png"));

    game = new Game();

    return a.exec();
}
