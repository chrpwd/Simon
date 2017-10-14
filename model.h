/*
the header file for the Model class, which has all the logic for the simon game

kira parker u1073760
christian purdy u0728219
october 2017
A5: a simon game

github: https://github.com/University-of-Utah-CS3505/simon-mv-app-cs3505-f17-kiraclimber
*/

#ifndef MODEL_H
#define MODEL_H

#include <QObject>
#include <QTimer>
#include <vector>

class Model : public QObject
{
    Q_OBJECT
public:
    explicit Model(QObject *parent = nullptr);

    void reset(); //resets the game if the user has chosen to restart after losing

signals:
    void gameStarted(bool); //emitted from the startGame slot, disables the start button (boolean param should be false)
    void enablePlayerButtons(bool); //true if the player should be able to hit their buttons, false otherwise
    void hitRedButton(); //emitted when the computer "hits" the red button
    void hitBlueButton(); //emitted when the computer "hits" the blue button

    void endGame(); //emitted when the user has hit the wrong button and the game ends

    void updateProgress(int); //emitted when the person makes a move and the progress bar needs to be updated

    void makeFaster(); //emitted when the game should speed up


public slots:
    void startGame(); //called when the game should start
    void computersTurn(); //called when the computer should play the next pattern
    void playNextInPattern(); //called when its time to play the next color in the pattern

    void pressedBlueButton(); //called when the user presses the blue button
    void pressedRedButton(); //called when the user presses the red button

private:
    std::vector<int> pattern; //keeps track of the pattern the computer is playing (red = 0, blue = 1)
    unsigned int currentIndexInPattern; //the current index of the pattern that the computer/user is playing
};

#endif // MODEL_H
