#ifndef OBSERVABLEPROPERTY_H
#define OBSERVABLEPROPERTY_H

#include <functional>
#include "observablepropertybase.h"

template<class T>
class ObservableProperty : public ObservablePropertyBase
{
public:
    ObservableProperty( QObject* parent = nullptr )
        : ObservableProperty( {}, []{}, []{}, parent )
    {
    }
    ObservableProperty( const std::function<QVariant(const T&)>& getter,
                        QObject* parent = nullptr )
        : ObservableProperty( {}, getter, []{}, parent )
    {
    }
    ObservableProperty( const std::function<QVariant(const T&)>& getter,
                        const std::function<void(T&, const QVariant&)>& setter,
                        QObject* parent = nullptr )
        : ObservableProperty( {}, getter, setter, parent )
    {
    }
    ObservableProperty( const T& value,
                        QObject* parent = nullptr )
        : ObservableProperty( value, []{}, []{}, parent )
    {
    }
    ObservableProperty( const T& value,
                        const std::function<QVariant(const T&)>& getter,
                        QObject* parent = nullptr )
        : ObservableProperty( value, getter, []{}, parent )
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
        assert( getter != nullptr );
        assert( setter != nullptr );
    }
    virtual ~ObservableProperty() = default;

protected:
    virtual QVariant valueProperty() const override
    {
        return m_getter( m_value );
    }

    virtual void setValueProperty( const QVariant& value ) override
    {
        if ( valueProperty() != value )
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

    bool setValue( const T& data )
    {
        bool ret = false;
        if ( m_value != data )
        {
            m_value = data;
            ret = true;
            raiseValuePropertyChanged();
        }
        return ret;
    }

private:
    T m_value = {};
    std::function<QVariant(const T&)> m_getter = nullptr;
    std::function<void(T&, const QVariant&)> m_setter = nullptr;
};

#endif // OBSERVABLEPROPERTY_H
