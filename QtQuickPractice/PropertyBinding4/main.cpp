#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <QQmlContext>
#include "foo.h"
#include "bar.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    qmlRegisterType<Foo>( "FooLibrary", 1, 0, "Foo" );
    qmlRegisterType<Bar>();  // QML側にBarの型情報を登録する

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
