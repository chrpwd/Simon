#include "model.h"

Model::Model(QObject *parent) : QObject(parent)
{
}

void Model::startGame() {
    emit gameStarted(true);
    //emit hitRedButton();
    //emit hitBlueButton();
}
