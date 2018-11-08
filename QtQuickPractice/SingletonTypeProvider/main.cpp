#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <QQmlContext>
#include <QObject>
#include "foo.h"
#include "bar.h"

// Fooインスタンスを生成するコールバック関数
static QObject* foo_instance_provider( QQmlEngine* engine, QJSEngine* scriptEngine )
{
    Q_UNUSED(engine)
    Q_UNUSED(scriptEngine)

    Foo* foo = new Foo();
    return foo;
}

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    // FooをシングルトンとしてQMLに登録する
    // あくまでQML内でのシングルトンであり、C++からみると単にnewしているだけでなので呼び出し禁止
    qmlRegisterSingletonType<Foo>( "FooLibrary", 1, 0, "Foo", foo_instance_provider );
    qmlRegisterType<Bar>();

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
