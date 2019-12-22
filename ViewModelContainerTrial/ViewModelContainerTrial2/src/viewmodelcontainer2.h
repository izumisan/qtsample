#ifndef VIEWMODELCONTAINER2_H
#define VIEWMODELCONTAINER2_H

#include <any>
#include <QObject>
#include <QMap>
#include <QString>
#include <QDebug>

class ViewModelContainer2 : public QObject
{
    Q_OBJECT
public:
    static const std::unique_ptr<ViewModelContainer2>& instance()
    {
        struct ctor_permission : public ViewModelContainer2
        {
            using ViewModelContainer2::ViewModelContainer2;
        };
        static std::unique_ptr<ViewModelContainer2>&& singleton = std::make_unique<ctor_permission>();
        return singleton;
    }

private:
    ViewModelContainer2() = default;
public:
    virtual ~ViewModelContainer2() = default;

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
            m_vms.insert( key, vm );
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
            m_vms.insert( key, vm );
        }
    }

    template<class ViewModelType>
    std::shared_ptr<ViewModelType> getSharedPtr( const QString& name )
    {
        std::shared_ptr<ViewModelType> ret {};
        auto&& key = name.toLower();
        if ( hasKey( key ) )
        {
            ret = std::any_cast<std::shared_ptr<ViewModelType>>( m_vms.value( key ) );
        }
        return ret;
    }

    template<class ViewModelType>
    ViewModelType* getPtr( const QString& name )
    {
        ViewModelType* ret {};
        auto&& key = name.toLower();
        if ( hasKey( key ) )
        {
            ret = std::any_cast<ViewModelType*>( m_vms.value( key ) );
        }
        return ret;
    }

    template<class ValutType>
    ValutType get( const QString& name )
    {
        ValutType ret {};
        auto&& key = name.toLower();
        if ( hasKey( key ) )
        {
            ret = std::any_cast<ValutType>( m_vms.value( key ) );
        }
        return ret;
    }

private:
    bool hasKey( const QString& key )
    {
        return m_vms.find( key ) != m_vms.cend();
    }

private:
    QMap<QString, std::any> m_vms {};
};

#endif // VIEWMODELCONTAINER2_H
