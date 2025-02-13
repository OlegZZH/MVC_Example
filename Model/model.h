//
// Created by oleg on 13.02.2025.
//

#ifndef MODEL_H
#define MODEL_H
#include <QObject>


class Model : public QObject {
    Q_OBJECT
    Q_PROPERTY(int counter READ getCounter WRITE setCounter NOTIFY counterChanged)
signals:
    void counterChanged(int newCounter);

public:
    explicit Model(QObject *parent = nullptr):QObject(parent){};
    int getCounter() {
        return m_counter;
    };
    void setCounter(int counter) {
        m_counter = counter;
        emit counterChanged(m_counter);
    };

private:
    int m_counter =0;
};


#endif //MODEL_H
