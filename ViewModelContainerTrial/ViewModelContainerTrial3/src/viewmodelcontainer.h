#ifndef VIEWMODELCONTAINER_H
#define VIEWMODELCONTAINER_H

#include <QObject>
#include <type_traits>
#include <typeinfo>
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
    ViewModelContainer() = default;
public:
    virtual ~ViewModelContainer() = default;

    template <class ViewModelType>
    void registerInstance( const std::shared_ptr<ViewModelType>& vm, const QString& name = "" )
    {
        if ( std::is_base_of<QObject, ViewModelType>::value )
        {
            auto key = name;
            if ( key.isEmpty() )
            {
                key = QString( typeid(ViewModelType).name() ).replace( "class ", "" ).toLower();
            }

            if ( m_vms.find( key ) == m_vms.cend() )
            {
                // 親オブジェクトが設定されていない場合は、ViewModelContainerを親に設定する
                // 親オブジェクトが未設定のままだと、QMLエレメントの破壊時に連動してdeleteされしまい、shared_ptrのdelete時に2重deleteでエラーとなる
                if ( vm->parent() == nullptr )
                {
                    vm->setParent( this );
                }
                m_vms.insert( key, vm );
            }
            else
            {
                qDebug() << QString(u8"%1 has already exists.").arg(key);
            }
        }
        else
        {
            qDebug() << u8"ViewModelType need to be QObject subclass.";
        }
    }

    template <class ViewModelType>
    std::shared_ptr<ViewModelType> get( const QString& name )
    {
        std::shared_ptr<ViewModelType> ret {};
        auto key = name.toLower();
        if ( m_vms.find( key ) != m_vms.cend() )
        {
            ret = std::dynamic_pointer_cast<ViewModelType>( m_vms.value( key ) );
        }
        return ret;
    }

private:
    QMap<QString, std::shared_ptr<QObject>> m_vms {};
};

#endif // VIEWMODELCONTAINER_H
