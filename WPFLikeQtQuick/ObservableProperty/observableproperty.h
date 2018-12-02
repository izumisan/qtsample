#ifndef OBSERVABLEPROPERTY_H
#define OBSERVABLEPROPERTY_H

#include <functional>
#include <type_traits>
#include "observablepropertybase.h"

template<class T>
class ObservableProperty : public ObservablePropertyBase
{
public:
    ObservableProperty( QObject* parent = nullptr )
        : ObservablePropertyBase( parent )
    {
    }
    ObservableProperty( const T& data,
                        QObject* parent = nullptr )
        : m_data( data )
        , ObservablePropertyBase( parent )
    {
    }
    ObservableProperty( const T& data,
                        const std::function<QString(const T&)>& getter,
                        QObject* parent = nullptr )
        : m_data( data )
        , m_getter( getter )
        , ObservablePropertyBase( parent )
    {
    }
    ObservableProperty( const T& data,
                        const std::function<QString(const T&)>& getter,
                        const std::function<void(T&, const QString&)>& setter,
                        QObject* parent = nullptr )
        : m_data( data )
        , m_getter( getter )
        , m_setter( setter )
        , ObservablePropertyBase( parent )
    {
    }
    virtual ~ObservableProperty() = default;

public:
    virtual QString valueProperty() const override
    {
        return m_getter( m_data );
    }

    virtual void setValueProperty( const QString& value ) override
    {
        if ( ( valueProperty() != value ) && ( m_setter != nullptr ) )
        {
            m_setter( m_data, value );
            raiseValuePropertyChanged();
        }
    }

public:
    T data() const
    {
        return m_data;
    }

    void setData( const T& data )
    {
        m_data = data;
    }

private:
    T m_data = {};
    std::function<QString(const T&)> m_getter = [](const T& data){ return data; };
    //std::function<void(T&, const QString&)> m_setter = [](T& data, const QString& value){ /*TODO*/ };
    std::function<void(T&, const QString&)> m_setter = nullptr;
};

#endif // OBSERVABLEPROPERTY_H
