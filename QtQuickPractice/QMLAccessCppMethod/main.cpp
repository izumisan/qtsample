#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <QQmlContext>
#include "foo.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    Foo foo;

    // QMLにfooオブジェクトをセット
    engine.rootContext()->setContextProperty( "foodata", &foo );

    return app.exec();
}
