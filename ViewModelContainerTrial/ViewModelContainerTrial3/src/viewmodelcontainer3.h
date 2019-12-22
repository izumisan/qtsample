#ifndef VIEWMODELCONTAINER3_H
#define VIEWMODELCONTAINER3_H

#include <any>
#include <QObject>
#include <QMap>
#include <QString>
#include <QDebug>

class ViewModelContainer3 : public QObject
{
    Q_OBJECT
public:
    static const std::unique_ptr<ViewModelContainer3>& instance()
    {
        struct ctor_permission : public ViewModelContainer3
        {
            using ViewModelContainer3::ViewModelContainer3;
        };
        static std::unique_ptr<ViewModelContainer3>&& singleton = std::make_unique<ctor_permission>();
        return singleton;
    }

private:
    ViewModelContainer3() = default;
public:
    virtual ~ViewModelContainer3() = default;

public:
    template<class ViewModelType>
    void registerPtr( ViewModelType* vm, const QString& name = "" )
    {
        auto key = name;
        if ( key.isEmpty() )
        {
            key = QString( typeid(std::remove_pointer<ViewModelType>::type).name() ).replace( "class ", "" ).toLower();
        }
        if ( hasKey( key ) != true )
        {
            if ( vm->parent() == nullptr )
            {
                vm->setParent( this );
            }
            m_vms.insert( key, std::make_tuple<std::any, std::function<QObject*(const std::any&)>>( vm, [](const std::any& value){ return std::any_cast<ViewModelType*>( value ); } ) );
        }
    }

    template<class ViewModelType>
    void registerSharedPtr( const std::shared_ptr<ViewModelType>& vm, const QString& name = "" )
    {
        auto key = name;
        if ( key.isEmpty() )
        {
            key = QString( typeid(ViewModelType).name() ).replace( "class ", "" ).toLower();
        }
        if ( hasKey( key ) != true )
        {
            if ( vm->parent() == nullptr )
            {
                vm->setParent( this );
            }
            m_vms.insert( key, std::make_tuple<std::any, std::function<QObject*(const std::any&)>>( vm, [](const std::any& value){ return std::any_cast<std::shared_ptr<ViewModelType>>( value ).get(); } ) );
        }
    }

    template<class ViewModelType>
    std::shared_ptr<ViewModelType> getSharedPtr( const QString& name ) const
    {
        std::shared_ptr<ViewModelType> ret {};
        auto&& key = name.toLower();
        if ( hasKey( key ) )
        {
            ret = std::any_cast<std::shared_ptr<ViewModelType>>( std::get<0>( m_vms.value( key ) ) );
        }
        return ret;
    }

    template<class ViewModelType>
    ViewModelType* getPtr( const QString& name ) const
    {
        ViewModelType* ret {};
        auto&& key = name.toLower();
        if ( hasKey( key ) )
        {
            ret = std::any_cast<ViewModelType*>( std::get<0>( m_vms.value( key ) ) );
        }
        return ret;
    }

    QObject* get( const QString& name ) const
    {
        QObject* ret {};
        auto&& key = name.toLower();
        if ( hasKey( key ) )
        {
            auto&& value = m_vms.value( key );
            auto&& item = std::get<0>( value );
            auto&& func = std::get<1>( value );
            ret = func( item );
        }
        return ret;
    }

private:
    bool hasKey( const QString& key ) const
    {
        return m_vms.find( key ) != m_vms.cend();
    }

private:
    QMap<QString, std::tuple<std::any, std::function<QObject*(const std::any&)>>> m_vms {};
};

#endif // VIEWMODELCONTAINER3_H
