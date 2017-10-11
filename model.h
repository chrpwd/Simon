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

    void reset();

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
    std::vector<int> pattern; //red = 0, blue = 1
    unsigned int currentIndexInPattern;
};

#endif // MODEL_H
