#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "viewmodelcontainer.h"
#include "fooviewmodel.h"
#include "barviewmodel.h"
#include "viewmodelprovider.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    {
        auto&& container = ViewModelContainer::instance();
        container->registerInstance<FooViewModel>( std::make_shared<FooViewModel>(), "foo" );
        container->registerInstance<BarViewModel>( std::make_shared<BarViewModel>(), "bar" );
    }

    QGuiApplication app(argc, argv);

    qmlRegisterType<FooViewModel>( "viewmodels", 1, 0, "FooViewModel" );
    qmlRegisterType<BarViewModel>( "viewmodels", 1, 0, "BarViewModel" );
    qmlRegisterSingletonType<ViewModelProvider>( "viewmodels", 1, 0, "ViewModelProvider", []( QQmlEngine* engine, QJSEngine* scriptEngine ) -> QObject*
    {
        Q_UNUSED(engine)
        Q_UNUSED(scriptEngine)
        return new ViewModelProvider();
    } );

    QQmlApplicationEngine engine;
    engine.addImportPath(QStringLiteral("qrc:/qml"));
    engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
