#include "model.h"
#include <cstdlib>

Model::Model(QObject *parent) : QObject(parent)
{
    currentIndexInPattern = 0;
}

void Model::startGame() {
    emit gameStarted(false);
    computersTurn();
    //emit hitRedButton();
    //emit hitBlueButton();
}

void Model::computersTurn(){
    for(int i=0; i<10; i++){
        pattern.push_back(rand()%2);
    }
    playNextInPattern();
    //displayTimer.start(20);
//    for(int num: pattern){
//        if(num == 0){
//            hitRedButton();
//        }
//        else{
//            hitBlueButton();
//        }
//    }
    //emit playersTurn(true);
}

void Model::playNextInPattern(){
    if(currentIndexInPattern == pattern.size()){
        emit playersTurn(true);
    }
    else if(pattern[currentIndexInPattern] == 0){
        hitRedButton();
    }
    else{
        hitBlueButton();
    }
}
