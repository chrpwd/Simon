#include "view.h"
#include "ui_view.h"
#include "model.h"

View::View(Model& model, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::View)
{
    ui->setupUi(this);
    ui->redButton->setStyleSheet( QString("QPushButton {background-color: rgb(200,0,0);} QPushButton:pressed {background-color: rgb(255,0,0);}"));
    ui->blueButton->setStyleSheet( QString("QPushButton {background-color: rgb(0,0,200);} QPushButton:pressed {background-color: rgb(0,0,255);}"));
    //connect start button clicked signal to model's startGame slot
    connect(ui->startButton, &QPushButton::clicked, &model, &Model::startGame);
    //connect gameStarted signal to setEnabled slot for start button
    connect(&model, &Model::gameStarted, ui->startButton, &QPushButton::setEnabled);

    //connect hitRed(Blue)Button signals to changeRed(Blue)ButtonColor slots
    connect(&model, &Model::hitRedButton, this, &View::changeRedButtonColor);
    connect(&model, &Model::hitBlueButton, this, &View::changeBlueButtonColor);
}

void View::changeRedButtonColor(){
    ui->redButton->setStyleSheet("background-color: rgb(255,0,0);");
}

void View::changeBlueButtonColor(){
    ui->blueButton->setStyleSheet("background-color: rgb(0,0,255);");
}

View::~View()
{
    delete ui;
}
