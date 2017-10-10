#ifndef MODEL_H
#define MODEL_H

#include <QObject>

class Model : public QObject
{
    Q_OBJECT
public:
    explicit Model(QObject *parent = nullptr);

signals:
    void modelUpdated(int);

public slots:
    void updateModel();

private:
    int data;
};

#endif // MODEL_H
