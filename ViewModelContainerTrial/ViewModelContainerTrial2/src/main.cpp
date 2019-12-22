#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "viewmodelcontainer2.h"
#include "fooviewmodel.h"
#include "barviewmodel.h"
#include "viewmodelprovider2.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    auto&& container = ViewModelContainer2::instance();
    container->registerSharedPtr<FooViewModel>( std::make_shared<FooViewModel>() );
    container->registerPtr<BarViewModel>( new BarViewModel() );

    QGuiApplication app(argc, argv);

    qmlRegisterType<FooViewModel>( "viewmodels", 1, 0, "FooViewModel" );
    qmlRegisterType<BarViewModel>( "viewmodels", 1, 0, "BarViewModel" );
    qmlRegisterSingletonType<ViewModelProvider2>( "viewmodels", 1, 0, "ViewModelProvider2", []( QQmlEngine* engine, QJSEngine* scriptEngine ) -> QObject*
    {
        Q_UNUSED(engine)
        Q_UNUSED(scriptEngine)
        return new ViewModelProvider2();
    } );

    QQmlApplicationEngine engine;
    engine.addImportPath(QStringLiteral("qrc:/qml"));
    engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
