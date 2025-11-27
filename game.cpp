#include "game.h"
#include "player.h"
#include <QGraphicsScene>
#include <QTimer>
#include <QBrush>
#include <QImage>

#define SCROLL_SPEED 2

Game::Game(QWidget* parent): QGraphicsView(parent)
{
    myscene= new QGraphicsScene(this);
    this->setScene(myscene);
    setFocusPolicy(Qt::NoFocus);

    myscene->setSceneRect(0,0,1080,500);
    /*
    myscene->setBackgroundBrush(QBrush(QImage(":/Graphics/Background_L1.png")));
    QImage bg(":/Graphics/Background_L1.png");
    myscene->setBackgroundBrush(QBrush(bg));
    */

    // *** 2. ADD MOVEABLE BACKGROUND ITEMS ***

    // Background 1 (The main screen view)
    QPixmap bg_pixmap(":/Graphics/Background_L1.png");
    background1 = new QGraphicsPixmapItem(bg_pixmap);
    background1->setPos(0, 0); // Start at the left of the scene
    myscene->addItem(background1);

    // Background 2 (Stitched immediately after background 1 for looping)
    background2 = new QGraphicsPixmapItem(bg_pixmap);
    // Set position right after background1
    background2->setPos(bg_pixmap.width(), 0);
    myscene->addItem(background2);
    // ------------------------------------------------------------------





    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //this->setFixedSize(1080,500);

    tayar = new Player();
    myscene->addItem(tayar);
    tayar->setFlag(QGraphicsItem::ItemIsFocusable);
    tayar->setFocus();


    // ------------------------------------------------------------------
    // *** 3. SETUP SCROLL TIMER ***
    QTimer* scrollTimer = new QTimer(this);
    scrollTimer->start(20); // Move every 20ms for smooth motion
    connect(scrollTimer, &QTimer::timeout, this, &Game::scrollBackground);
    // ------------------------------------------------------------------




    QTimer* FallDownTimer = new QTimer(this);
    FallDownTimer-> start(20);
    connect(FallDownTimer, &QTimer::timeout, tayar, &Player::UpdateYPosition);


}
void Game::scrollBackground()
{
    // Move both backgrounds backward (to the left)
    background1->setX(background1->x() - SCROLL_SPEED);
    background2->setX(background2->x() - SCROLL_SPEED);

    int bg_width = background1->pixmap().width();

    // Logic for Seamless Looping:
    // When the first background moves completely off the screen (x < -width),
    // reposition it immediately after the second background.
    if (background1->x() < -bg_width) {
        background1->setX(background2->x() + bg_width);
    }

    // When the second background moves completely off the screen,
    // reposition it immediately after the first background.
    if (background2->x() < -bg_width) {
        background2->setX(background1->x() + bg_width);
    }
}



void Game::keyPressEvent(QKeyEvent* event)
{
    QGraphicsView::keyPressEvent(event);
}

Game::~Game()
{

}
