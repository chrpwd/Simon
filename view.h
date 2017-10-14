/*
the header file for the View class, which controls the functionality of the game window

kira parker u1073760
christian purdy u0728219
october 2017
A5: a simon game

github: https://github.com/University-of-Utah-CS3505/simon-mv-app-cs3505-f17-kiraclimber
*/

#ifndef VIEW_H
#define VIEW_H

#include <QMainWindow>
#include <QTimer>
#include "model.h"
#include<QMessageBox>

namespace Ui {
class View;
}

class View : public QMainWindow
{
    Q_OBJECT

public:
    explicit View(Model& model, QWidget *parent = 0);
    ~View();

public slots:
    void startGame(); //called when the user has pushed the start/restart button

    //used to let the computer play out the pattern
    void highlightRedButton(); //changes the color of the red button when it is used in the pattern
    void highlightBlueButton(); //changes the color of the blue button when it is used in the pattern
    void unhighlightButtons(); //changes the color of the buttons back to their original colors

    //used to let the user play the pattern
    void unhighlightBlueButton();
    void pressedBlueButton();
    void unhighlightRedButton();
    void pressedRedButton();

    void endGame(); //called when the user has pressed the wrong button

    void makeFaster(); //called when the user has successfully completed the pattern, increases speed at which computer plays back pattern

    void computersTurn(); //used so the displayTimer can call computersTurn which sends out a signal to the model (couldn't make it work without intermediate)

signals:
    void playNextInPattern(); //tells model that it's time to play the next color in the pattern

    void computersTurnS(); //tells model that it's the computer's turn

private:
    Ui::View *ui;
    QTimer displayTimer; //times how long to highlight buttons when they are hit/played by the computer
    int waitTime; //how long the buttons are lit up when the computer plays the pattern
    int waitTimeForUser; //how long the buttons are lit up when the user hits them
    QMessageBox youLoseBox; //box that pops up when the user has lost the game
};

#endif // VIEW_H
