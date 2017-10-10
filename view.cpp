#include "view.h"
#include "ui_view.h"
#include "model.h"

View::View(Model& model, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::View)
{
    ui->setupUi(this);
    connect(ui->redButton, &QPushButton::clicked,
            &model, &Model::updateModel);
    //connect(&model, &Model::modelUpdated,
    //        ui->spinBox, &QSpinBox::setValue);
}

View::~View()
{
    delete ui;
}
