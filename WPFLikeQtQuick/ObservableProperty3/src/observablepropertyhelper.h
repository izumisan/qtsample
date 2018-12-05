#ifndef OBSERVABLEPROPERTYHELPER_H
#define OBSERVABLEPROPERTYHELPER_H

#include <functional>
#include <QVariant>

template<class T>
class ObservablePropertyHelper
{
public:
    static std::function<QVariant(const T&)> getter()
    {
        return [](const T& data){ return data; };
    }

    static std::function<void(T&, const QVariant&)> setter()
    {
        return [](T& data, const QVariant& value ){ data = value.value<T>(); };
    }
};

#endif // OBSERVABLEPROPERTYHELPER_H
