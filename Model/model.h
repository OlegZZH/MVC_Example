//
// Created by oleg on 13.02.2025.
//

#ifndef MODEL_H
#define MODEL_H
#include <QObject>


class Model : public QObject {
    Q_OBJECT
    Q_PROPERTY(int counter READ getCounter WRITE setCounter NOTIFY counterChanged)
    Q_PROPERTY(bool decrementEnabled READ getDecrementEnabled WRITE setDecrementEnabled NOTIFY decrementEnabledChanged)
signals:
    void counterChanged(int newCounter);
    void decrementEnabledChanged(bool newDecrementEnabled);

public:
    explicit Model(QObject *parent = nullptr): QObject(parent) {
    };

    int getCounter() {
        return m_counter;
    };
    void setCounter(int counter) {
        m_counter = counter;
        emit counterChanged(m_counter);
    };
    bool getDecrementEnabled() {
        return m_decrementEnabled;
    }
    void setDecrementEnabled(bool decrementEnabled) {
        m_decrementEnabled = decrementEnabled;
        emit decrementEnabledChanged(m_decrementEnabled);
    }


private:
    int m_counter = 0;
    bool m_decrementEnabled = false;
};


#endif //MODEL_H
