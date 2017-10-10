#ifndef VIEW_H
#define VIEW_H

#include <QMainWindow>
#include <QTimer>
#include "model.h"

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
    //used to let the computer play out the pattern
    void highlightRedButton(); //changes the color of the red button when it is used in the pattern
    void highlightBlueButton(); //changes the color of the blue button when it is used in the pattern
    void unhighlightButtons(); //changes the color of the buttons back to their original colors

    //used to let the user play the pattern
    void unhighlightBlueButton();
    void pressedBlueButton();
    void unhighlightRedButton();
    void pressedRedButton();

    void endGame();

signals:
    void playNextInPattern(); //tells model that it's time to play the next color in the pattern

private:
    Ui::View *ui;
    QTimer displayTimer;
    int waitTime; //how long the buttons are lit up when the computer plays the pattern
    int waitTimeForUser; //how long the buttons are lit up when the user hits them
};

#endif // VIEW_H
