#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <QDebug>
#include "fizzbuzz.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    auto&& fizzbuzz = new FizzBuzz();
    QObject* rootObject = engine.rootObjects().first();

    // QMLシグナルをC++スロットにコネクト
    QObject::connect( rootObject, SIGNAL( buttonClicked() ),
                      fizzbuzz, SLOT( next() ) );

    // C++シグナルをQMLスロット(QML関数)にコネクト
    QObject::connect( fizzbuzz, SIGNAL( updated(QVariant) ),
                      rootObject, SLOT( setLabelText(QVariant) ) );

    return app.exec();
}
