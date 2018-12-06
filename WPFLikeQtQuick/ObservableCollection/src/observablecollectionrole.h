#ifndef OBSERVABLECOLLECTIONROLE_H
#define OBSERVABLECOLLECTIONROLE_H

#include <functional>
#include <QVariant>
#include <QString>

template<class T>
class ObservableCollectionRole
{
public:
    ObservableCollectionRole( const QString& roleName,
                              const std::function<QVariant(const T&)>& getter,
                              const std::function<void(T&, const QVariant&)>& setter )
        : m_roleName( roleName )
        , m_getter( getter )
        , m_setter( setter )
    {
    }

public:
    QString roleName() const { return m_roleName; }
    std::function<QVariant(const T&)> getter() const { return m_getter; }
    std::function<void(T&, const QVariant&)> setter() const { return m_setter; }

private:
    QString m_roleName = {};
    std::function<QVariant(const T&)> m_getter = [](const T&){};
    std::function<void(T&, const QVariant&)> m_setter = [](T&, const QVariant&){};
};

#endif // OBSERVABLECOLLECTIONROLE_H
