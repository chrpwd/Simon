/*
the main file for the game, which starts it running

kira parker u1073760
christian purdy u0728219
october 2017
A5: a simon game

github: https://github.com/University-of-Utah-CS3505/simon-mv-app-cs3505-f17-kiraclimber
*/

#include "view.h"
#include <QApplication>
#include "model.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Model m;
    View w(m);
    w.show();

    return a.exec();
}
