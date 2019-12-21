#ifndef VIEWMODELCONTAINER_H
#define VIEWMODELCONTAINER_H

#include <QObject>
#include <type_traits>
#include <memory>
#include <cassert>
#include <QMap>
#include <QString>
#include <QDebug>

class ViewModelContainer : public QObject
{
    Q_OBJECT
public:
    static const std::unique_ptr<ViewModelContainer>& instance()
    {
        struct ctor_permission : public ViewModelContainer
        {
            using ViewModelContainer::ViewModelContainer;
        };
        static std::unique_ptr<ViewModelContainer>&& singleton = std::make_unique<ctor_permission>();
        return singleton;
    }
private:
    ViewModelContainer()
        : QObject()
    {
    }
public:
    virtual ~ViewModelContainer()
    {
    }

    template <class ViewModelType>
    void registerInstance( const std::shared_ptr<ViewModelType>& vm, const QString& key = "" )
    {
        if ( std::is_base_of<QObject, ViewModelType>::value )
        {
            if ( key.isEmpty() != true )
            {
                m_vms.insert( key, vm );
            }
        }
        else
        {
            assert(!u8"ViewModelTypeはQObjectの必要があります" );
        }
    }

    template <class ViewModelType>
    std::shared_ptr<ViewModelType> get( const QString& key )
    {
        //@@@ keyチェック省略
        return std::dynamic_pointer_cast<ViewModelType>( m_vms.value( key ) );
    }

    QObject* getA( const QString& key )
    {
        //@@@ keyチェック省略
        return m_vms.value( key ).get();
    }

private:
    QMap<QString, std::shared_ptr<QObject>> m_vms {};
};

#endif // VIEWMODELCONTAINER_H
