#ifndef VIEW_H
#define VIEW_H

#include <QMainWindow>
#include "model.h"
namespace Ui {
class View;
}

class View : public QMainWindow
{
    Q_OBJECT

public:
    explicit View(Model& model, QWidget *parent = 0);
    ~View();

public slots:
    void changeRedButtonColor();
    void changeBlueButtonColor();

private:
    Ui::View *ui;
};

#endif // VIEW_H
