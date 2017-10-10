#include "model.h"

Model::Model(QObject *parent) : QObject(parent)
{
    data = 0;
}

void Model::updateModel() {
    data++;
    emit modelUpdated(data);
}
