#ifndef VIWEMODELBASE_H
#define VIWEMODELBASE_H

#include <functional>
#include <QObject>
#include "observableproperty.h"

#define OBSERVABLE_PROPERTY( name, var ) \
    Q_PROPERTY( ObservablePropertyBase* name READ get_##var CONSTANT ) \
    ObservablePropertyBase* get_##var() { return &( var ); }

class ViewModelBase : public QObject
{
    Q_OBJECT
public:
    explicit ViewModelBase( QObject* parent = nullptr );
    virtual ~ViewModelBase() = default;

    template<class T>
    bool setProperty( ObservableProperty<T>& property,
                      const T& value,
                      const std::function<void()>& onChanged = nullptr )
    {
        bool ret = property.setValue( value );
        if ( ret && onChanged )
        {
            onChanged();
        }
        return ret;
    }
};

#endif // VIWEMODELBASE_H
