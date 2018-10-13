#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "foo.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    // QMLにFooクラスを登録
    // ライブラリ名, メジャーバージョン, マイナーバージョン, QMLエレメント名
    qmlRegisterType<Foo>( "FooLibrary", 1, 0, "Foo" );

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
