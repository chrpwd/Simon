#include "model.h"
#include <cstdlib>

Model::Model(QObject *parent) : QObject(parent)
{
    currentIndexInPattern = 0;
}

//starts the game, the computer plays a 1-color pattern
void Model::startGame() {
    emit gameStarted(false);
    computersTurn();
}

//the computer adds a color to the end of the pattern and starts playing the pattern
void Model::computersTurn(){
    currentIndexInPattern = 0;
    pattern.push_back(rand()%2);
    playNextInPattern();
}

void Model::playNextInPattern(){
    if(currentIndexInPattern == pattern.size()){
        emit playersTurn(true);
        currentIndexInPattern = 0;
    }
    else if(pattern[currentIndexInPattern] == 0){
        emit hitRedButton();
        currentIndexInPattern += 1;
    }
    else{
        emit hitBlueButton();
        currentIndexInPattern += 1;
    }
}

//called when the user has pressed the blue button, checks that pressing the blue button was the correct move to make.
//if pressing the blue button was incorrect, emits the endGame signal. if the user has correctly completed the pattern,
//tells the computer to play the next pattern.
void Model::pressedBlueButton(){
    if(pattern[currentIndexInPattern] != 1){
        emit endGame();
        return;
    }
    currentIndexInPattern += 1;
    if(currentIndexInPattern == pattern.size()){
        currentIndexInPattern = 0;
        computersTurn();
    }
}

//called when the user has pressed the red button, checks that pressing the red button was the correct move to make.
//if pressing the red button was incorrect, emits the endGame signal. if the user has correctly completed the pattern,
//tells the computer to play the next pattern.
void Model::pressedRedButton(){
    if(pattern[currentIndexInPattern] != 0){
        emit endGame();
        return;
    }
    currentIndexInPattern += 1;
    if(currentIndexInPattern == pattern.size()){
        currentIndexInPattern = 0;
        computersTurn();
    }
}
