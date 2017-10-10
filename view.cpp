#include "view.h"
#include "ui_view.h"
#include "model.h"

#include <unistd.h>

View::View(Model& model, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::View)
{
    ui->setupUi(this);
    //ui->redButton->setStyleSheet( QString("QPushButton {background-color: rgb(200,0,0);} QPushButton:pressed {background-color: rgb(255,0,0);}"));
    //ui->blueButton->setStyleSheet( QString("QPushButton {background-color: rgb(0,0,200);} QPushButton:pressed {background-color: rgb(0,0,255);}"));

    //connect start button clicked signal to model's startGame slot
    connect(ui->startButton, &QPushButton::clicked, &model, &Model::startGame);
    //connect gameStarted signal to setEnabled slot for start button
    connect(&model, &Model::gameStarted, ui->startButton, &QPushButton::setEnabled);

    //connect playersTurn signal to setEnabled slot for red and blue buttons
    connect(&model, &Model::playersTurn, ui->blueButton, &QPushButton::setEnabled);
    connect(&model, &Model::playersTurn, ui->redButton, &QPushButton::setEnabled);
    connect(&model, &Model::playersTurn, this, &View::playersTurn);

    //connect hitRed(Blue)Button signals to changeRed(Blue)ButtonColor slots
    connect(&model, &Model::hitRedButton, this, &View::highlightRedButton);
    connect(&model, &Model::hitBlueButton, this, &View::highlightBlueButton);

    //connects the display timer timeout to the unhighlight buttons method
    //connect(&displayTimer, &QTimer::timeout, this, &View::unhighlightButtons);

    connect(this, &View::playNextInPattern, &model, &Model::playNextInPattern);
}

void View::playersTurn(){
    ui->blueButton->setStyleSheet("background-color: rgb(0,255,0);");
    ui->redButton->setStyleSheet("background-color: rgb(0,255,0);");
}

void View::highlightRedButton(){
    ui->redButton->setStyleSheet("background-color: rgb(255,0,0);");
    //displayTimer.start(20);
    displayTimer.singleShot(2000, this, &View::unhighlightButtons);
}

void View::highlightBlueButton(){
    ui->blueButton->setStyleSheet("background-color: rgb(0,0,255);");
    //displayTimer.start(20);
    displayTimer.singleShot(2000, this, &View::unhighlightButtons);
}

void View::unhighlightButtons(){
    ui->blueButton->setStyleSheet("background-color: rgb(0,0,0);");
    ui->redButton->setStyleSheet("background-color: rgb(0,0,0);");
    usleep(20000);
    emit playNextInPattern();
}

View::~View()
{
    delete ui;
}
