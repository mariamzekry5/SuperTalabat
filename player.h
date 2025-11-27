#ifndef PLAYER_H
#define PLAYER_H


#include <QGraphicsItem>
#include <QObject>


class Player:public QObject ,public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    Player(QGraphicsItem* parent = nullptr);
};

#endif // PLAYER_H
