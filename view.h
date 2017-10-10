#ifndef VIEW_H
#define VIEW_H

#include <QMainWindow>
#include <QTimer>
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
    void highlightRedButton(); //changes the color of the red button when it is used in the pattern
    void highlightBlueButton(); //changes the color of the blue button when it is used in the pattern
    void unhighlightButtons(); //changes the color of the buttons back to their original colors
    void playersTurn();

signals:
    void playNextInPattern(); //tells model that its time to play the next color in the pattern

private:
    Ui::View *ui;
    QTimer displayTimer;
};

#endif // VIEW_H
