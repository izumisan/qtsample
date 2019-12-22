#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "viewmodelcontainer3.h"
#include "fooviewmodel.h"
#include "barviewmodel.h"
#include "viewmodelprovider3.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    auto&& container = ViewModelContainer3::instance();
    container->registerSharedPtr<FooViewModel>( std::make_shared<FooViewModel>() );
    container->registerPtr<BarViewModel>( new BarViewModel() );

    QGuiApplication app(argc, argv);

    qmlRegisterType<FooViewModel>( "viewmodels", 1, 0, "FooViewModel" );
    qmlRegisterType<BarViewModel>( "viewmodels", 1, 0, "BarViewModel" );
    qmlRegisterSingletonType<ViewModelProvider3>( "viewmodels", 1, 0, "ViewModelProvider3", []( QQmlEngine* engine, QJSEngine* scriptEngine ) -> QObject*
    {
        Q_UNUSED(engine)
        Q_UNUSED(scriptEngine)
        return new ViewModelProvider3();
    } );

    QQmlApplicationEngine engine;
    engine.addImportPath(QStringLiteral("qrc:/qml"));
    engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
