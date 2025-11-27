#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QKeyEvent>
#include <QGraphicsScene>

#include "player.h"

class Game : public QGraphicsView
{
    Q_OBJECT
    QGraphicsScene *myscene;
    Player* tayar;


public:
    Game (QWidget *parent = nullptr);
    ~Game();
};

#endif // GAME_H
