#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "foolistmodel.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    auto&& model = FooListModel();
    model.add( Foo( "white", QColor( Qt::white ) ) );
    model.add( Foo( "black", QColor( Qt::black ) ) );
    model.add( Foo( "cyan", QColor( Qt::cyan ) ) );
    model.add( Foo( "darkCyan", QColor( Qt::darkCyan ) ) );
    model.add( Foo( "red", QColor( Qt::red ) ) );
    model.add( Foo( "darkRed", QColor( Qt::darkRed ) ) );
    model.add( Foo( "magenta", QColor( Qt::magenta ) ) );
    model.add( Foo( "darkMagenta", QColor( Qt::darkMagenta ) ) );
    model.add( Foo( "green", QColor( Qt::green ) ) );
    model.add( Foo( "darkGreen", QColor( Qt::darkGreen ) ) );
    model.add( Foo( "yellow", QColor( Qt::yellow ) ) );
    model.add( Foo( "darkYellow", QColor( Qt::darkYellow ) ) );
    model.add( Foo( "blue", QColor( Qt::blue ) ) );
    model.add( Foo( "darkBlue", QColor( Qt::darkBlue ) ) );
    model.add( Foo( "gray", QColor( Qt::gray ) ) );
    model.add( Foo( "darkGray", QColor( Qt::darkGray ) ) );
    model.add( Foo( "lightGray", QColor( Qt::lightGray ) ) );

    QQmlApplicationEngine engine;

    engine.rootContext()->setContextProperty( "fooListModel", &model );

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
