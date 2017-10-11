#include "model.h"
#include <cstdlib>
#include <ctime>

Model::Model(QObject *parent) : QObject(parent)
{
    srand (time (0));
    currentIndexInPattern = 0;
    for(int i=0; i<2; i++){
        pattern.push_back(rand()%2);
    }
}

//starts the game, the computer plays a 1-color pattern
void Model::startGame() {
    emit gameStarted(false);
    computersTurn();
}

//the computer adds a color to the end of the pattern and starts playing the pattern
void Model::computersTurn(){
    emit updateProgress(0);
    currentIndexInPattern = 0;
    pattern.push_back(rand()%2);
    playNextInPattern();
}

//plays the next color in the pattern. if the end of the pattern has been reached, emits the playersTurn signal.
void Model::playNextInPattern(){
    if(currentIndexInPattern == pattern.size()){ //there is no next color
        emit enablePlayerButtons(true);
        currentIndexInPattern = 0;
    }
    else if(pattern[currentIndexInPattern] == 0){ //next color is red
        emit hitRedButton();
        currentIndexInPattern += 1;
    }
    else{ //next color is blue
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
        reset();
        return;
    }
    currentIndexInPattern += 1;
    emit updateProgress((100*currentIndexInPattern)/pattern.size());
    if(currentIndexInPattern == pattern.size()){
        currentIndexInPattern = 0;
        emit enablePlayerButtons(false);
        emit makeFaster();
    }
}

//called when the user has pressed the red button, checks that pressing the red button was the correct move to make.
//if pressing the red button was incorrect, emits the endGame signal. if the user has correctly completed the pattern,
//tells the computer to play the next pattern.
void Model::pressedRedButton(){
    if(pattern[currentIndexInPattern] != 0){
        emit endGame();
        reset();
        return;
    }
    currentIndexInPattern += 1;
    emit updateProgress((100*currentIndexInPattern)/pattern.size());
    if(currentIndexInPattern == pattern.size()){
        currentIndexInPattern = 0;
        emit enablePlayerButtons(false);
        emit makeFaster();
    }
}

void Model::reset(){
    pattern.clear();
    currentIndexInPattern = 0;
    for(int i=0; i<2; i++){
        pattern.push_back(rand()%2);
    }

}
