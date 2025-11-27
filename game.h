#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>

#include "player.h"

class Game : public QGraphicsView
{
    Q_OBJECT
    QGraphicsScene *myscene;
    Player* tayar;


public:
    Game (QWidget *parent = nullptr);
    ~Game();
    // *** ADD THIS: Background Item Pointer ***
    QGraphicsPixmapItem* background1;
    QGraphicsPixmapItem* background2; // For seamless looping (optional but recommended)
public slots:
    void scrollBackground(); // *** ADD THIS: New slot for movement ***
protected:
    void keyPressEvent(QKeyEvent* event) override;
};

#endif // GAME_H
