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

signals:
    void gameStarted(bool); //emitted from the startGame slot, disables the start button (boolean param should be false)
    void playersTurn(bool); //emitted when it is time for the player to hit the buttons (boolean param should be true)
    void hitRedButton(); //emitted when the computer "hits" the red button
    void hitBlueButton(); //emitted when the computer "hits" the blue button

public slots:
    void startGame(); //called when the game should start
    void computersTurn(); //called when the computer should play the next pattern
    void playNextInPattern(); //called when its time to play the next color in the pattern

private:
    std::vector<int> pattern;
    int currentIndexInPattern;
};

#endif // MODEL_H
