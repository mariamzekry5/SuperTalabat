#ifndef PLAYER_H
#define PLAYER_H


#include <QGraphicsItem>
#include <QObject>
#include <QKeyEvent>


class Player:public QObject ,public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    Player(QGraphicsItem* parent = nullptr);

public slots:
    void UpdateYPosition();

protected:
    void keyPressEvent(QKeyEvent* event) override;
    bool is_on_ground;
private:
    void Jump();
    // *** NEW VARIABLES FOR PHYSICS ***
    double y_velocity;  // Tracks the current vertical speed (pixels/tick)
    const double gravity = 1.0; // The acceleration due to gravity (constant)
    const double jump_speed = -15.0; // Initial upward speed (negative since QGraphicsScene Y-axis is inverted)

};

#endif // PLAYER_H
