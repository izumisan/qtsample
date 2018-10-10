#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    // ルート要素（Window）を取得
    QObject* rootObject = engine.rootObjects().first();

    // ルート要素から"textObject"を取得
    QObject* qmlTextObject = rootObject->findChild<QObject*>( "textObject" );

    // textプロパティの取得
    qDebug() << qmlTextObject->property( "text" );

    // textプロパティの書き換え
    qmlTextObject->setProperty( "text", "This text was overwritten by C++ code." );

    return app.exec();
}
