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
    ObservableProperty( const T& value,
                        QObject* parent = nullptr )
        : m_value( value )
        , ObservablePropertyBase( parent )
    {
    }
    ObservableProperty( const T& value,
                        const std::function<QVariant(const T&)>& getter,
                        QObject* parent = nullptr )
        : m_value( value )
        , m_getter( getter )
        , ObservablePropertyBase( parent )
    {
    }
    ObservableProperty( const T& value,
                        const std::function<QVariant(const T&)>& getter,
                        const std::function<void(T&, const QVariant&)>& setter,
                        QObject* parent = nullptr )
        : m_value( value )
        , m_getter( getter )
        , m_setter( setter )
        , ObservablePropertyBase( parent )
    {
    }
    virtual ~ObservableProperty() = default;

protected:
    virtual QVariant valueProperty() const override
    {
        return m_getter( m_value );
    }

    virtual void setValueProperty( const QVariant& value ) override
    {
        if ( ( valueProperty() != value ) && ( m_setter != nullptr ) )
        {
            m_setter( m_value, value );
            raiseValuePropertyChanged();
        }
    }

public:
    T value() const
    {
        return m_value;
    }

    void setValue( const T& data )
    {
        if ( m_value != data )
        {
            m_value = data;
            raiseValuePropertyChanged();
        }
    }

private:
    T m_value = {};
    std::function<QVariant(const T&)> m_getter = [](const T& value){ return value; };
    std::function<void(T&, const QVariant&)> m_setter = nullptr;
};

#endif // OBSERVABLEPROPERTY_H
