#include "game.h"
#include "player.h"
#include <QGraphicsScene>

Game::Game(QWidget* parent): QGraphicsView(parent)
{
    myscene= new QGraphicsScene(this);
    this->setScene(myscene);

    myscene->setSceneRect(0,0,1080,500);
    myscene->setBackgroundBrush(QBrush(QImage(":/Graphics/Background_L1.png")));
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setFixedSize(1080,500);
    tayar = new Player();
    myscene->addItem(tayar);

    QImage bg(":/Graphics/Background_L1.png");
    qDebug() << "BG is null?" << bg.isNull();
    myscene->setBackgroundBrush(QBrush(bg));

}

Game::~Game()
{

}
