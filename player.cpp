#include "player.h"

#include <QPixmap>


Player::Player(QGraphicsItem *parent)
{
    setPixmap(QPixmap(":/Graphics/Tayar.png"));
    this -> setPos(270,70);

}
