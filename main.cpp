#include "game.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Game SuperTalabat;
    SuperTalabat.show();
    return app.exec();
}
