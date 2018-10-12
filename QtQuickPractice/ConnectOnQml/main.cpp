#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <QQmlContext>
#include "fizzbuzz.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    auto&& fizzbuzz = new FizzBuzz();

    QQmlApplicationEngine engine;

    // FizzBuzzオブジェクトをセット
    engine.rootContext()->setContextProperty( "fizzbuzz", fizzbuzz );

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
