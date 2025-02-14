//
// Created by oleg on 13.02.2025.
//

#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include "Model/model.h"

class Controller : public QObject {
    Q_OBJECT

public:
    explicit Controller(Model *myModel, QObject *parent = nullptr): QObject(parent), model(myModel) {
    };

public slots:
    void buttonAction() {
        if (model->getDecrementEnabled()) {
            model->setCounter(model->getCounter() - 1);
        }
        else {
            model->setCounter(model->getCounter() + 1);
        }
    }
    void changeBehavior() {
        model->setDecrementEnabled(!model->getDecrementEnabled());
    }

private:
    Model *model;
};


#endif //CONTROLLER_H
