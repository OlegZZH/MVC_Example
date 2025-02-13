#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "Controller/controller.h"
#include "Model/model.h"

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);

    Model myModel;
    Controller myController(&myModel);
    QQmlApplicationEngine myView;

    myView.rootContext()->setContextProperty("myModel",&myModel);
    myView.rootContext()->setContextProperty("myController",&myController);
    QObject::connect(
        &myView, &QQmlApplicationEngine::objectCreationFailed, &app, []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    myView.loadFromModule("Example", "App");

    return app.exec();
}

