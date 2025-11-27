#include "player.h"

#include <QPixmap>
#include <QTimer>

#define GROUND_Y 180

Player::Player(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/Graphics/Tayar.png"));
    setScale(0.5);
    setPos(140,GROUND_Y);
    is_on_ground=true;
    y_velocity = 0.0; // Start with no vertical movement

}

void Player::Jump()
{
    if (is_on_ground) {
        // Set the initial upward velocity
        y_velocity = jump_speed;
        is_on_ground = false; // Player is now in the air
        // qDebug() << "Jumping! Initial velocity:" << y_velocity;
    }
}


void Player::UpdateYPosition() {
    // 1. Apply Gravity: Increase downward velocity every tick
    y_velocity += gravity;

    // 2. Calculate New Position: Move the player based on the current velocity
    double new_y = y() + y_velocity;

    // 3. Check for Landing
    if (new_y >= GROUND_Y)
    {
        // Player has hit or passed the ground level
        setPos(x(), GROUND_Y); // Snap to the exact ground position
        y_velocity = 0.0;     // Stop vertical movement

        if (!is_on_ground) {
            is_on_ground = true; // Player has landed
            // qDebug() << "Player landed.";
        }
    }
    else
    {
        // Player is in the air (rising or falling)
        setPos(x(), new_y);
    }
}


/*
void Player::Falldown(){
    if(y()>GROUND_Y)
    {
        //setPos(x(), GROUND_Y);
        if (!is_on_ground) is_on_ground = true;

        return;
    }

    setPos(x(), y()+2);

}
*/

void Player::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Up || event->key()==Qt::Key_Space){
        if (!event->isAutoRepeat())
            Jump();
    }
}


