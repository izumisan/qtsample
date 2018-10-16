#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <QQmlContext>
#include <QList>
#include "foo.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    // C++モデルデータ
    // （QList<Foo*>とすると上手く動作しない）
    auto&& foolist = QList<QObject*>
    {
        new Foo( "white", QColor( Qt::white ) ),
        new Foo( "black", QColor( Qt::black ) ),
        new Foo( "cyan", QColor( Qt::cyan ) ),
        new Foo( "darkCyan", QColor( Qt::darkCyan ) ),
        new Foo( "red", QColor( Qt::red ) ),
        new Foo( "darkRed", QColor( Qt::darkRed ) ),
        new Foo( "magenta", QColor( Qt::magenta ) ),
        new Foo( "darkMagenta", QColor( Qt::darkMagenta ) ),
        new Foo( "green", QColor( Qt::green ) ),
        new Foo( "darkGreen", QColor( Qt::darkGreen ) ),
        new Foo( "yellow", QColor( Qt::yellow ) ),
        new Foo( "darkYellow", QColor( Qt::darkYellow ) ),
        new Foo( "blue", QColor( Qt::blue ) ),
        new Foo( "darkBlue", QColor( Qt::darkBlue ) ),
        new Foo( "gray", QColor( Qt::gray ) ),
        new Foo( "darkGray", QColor( Qt::darkGray ) ),
        new Foo( "lightGray", QColor( Qt::lightGray ) )
    };

    // C++モデルデータをQMLにセット
    engine.rootContext()->setContextProperty( "foolist", QVariant::fromValue( foolist ) );

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
