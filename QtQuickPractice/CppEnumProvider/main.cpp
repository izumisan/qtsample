#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "fooenumclass.h"
#include "barenum.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    qmlRegisterUncreatableType<foo::FooEnumClass>( "viewmodel", 1, 0, "FooEnum", "Fail to register foo::FooEnumClass::FooEnum" );

    qmlRegisterUncreatableMetaObject( bar::staticMetaObject, "viewmodel", 1, 0, "Bar", "Fail to register bar::BarEnum" );

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
