#ifndef MODEL_H
#define MODEL_H

#include <QObject>

class Model : public QObject
{
    Q_OBJECT
public:
    explicit Model(QObject *parent = nullptr);

signals:
    void gameStarted(bool); //emitted from the startGame slot, disables the start button
    void hitRedButton();
    void hitBlueButton();

public slots:
    void startGame();

private:
};

#endif // MODEL_H
