#include <QGuiApplication>
#include <QQmlApplicationEngine>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    engine.addImportPath(QStringLiteral("qrc:/qml"));

//#if !defined(QT_NO_DEBUG)
//    // debugの場合、qmlファイルをロードする
//    engine.load(QUrl(QStringLiteral("qml/QtQuickApp/main.qml")));
//#else
//    // releaseの場合、リソースファイルをロードする
//    engine.load(QUrl(QStringLiteral("qrc:/qml/QtQuickApp/main.qml")));
//#endif
    engine.load(QUrl(QStringLiteral("qrc:/qml/QtQuickApp/main.qml")));

    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
