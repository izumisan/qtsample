#ifndef OBSERVABLECOLLECTION_H
#define OBSERVABLECOLLECTION_H

#include <functional>
#include "observablecollectionbase.h"

template<class T>
class ObservableCollection : public ObservableCollectionBase
{
public:
    ObservableCollection( QObject* parent = nullptr )
        : ObservableCollectionBase( parent )
    {
    }
    virtual ~ObservableCollection() = default;

public:
    virtual int rowCount( const QModelIndex& parent = QModelIndex() ) const override
    {
        Q_UNUSED( parent );
        return m_values.size();
    }

    virtual QVariant data( const QModelIndex& index, int role = Qt::DisplayRole ) const override
    {
        auto&& ret = QVariant();
        if ( index.isValid() )
        {
            constexpr int roleOffset = Qt::UserRole + 1;
            auto&& dataIndex = role - roleOffset;
            ret = m_getters.at( dataIndex )( m_values.at( dataIndex ) );
        }
        return ret;
    }

protected:
    virtual QHash<int, QByteArray> roleNames() const override
    {
        constexpr int roleOffset = Qt::UserRole + 1;
        QHash<int, QByteArray> ret {};
        for ( int i = 0; i < m_roles.size(); ++i )
        {
            auto&& role = roleOffset + i;
            ret.insert( role, m_roles.at( i ) );
        }
        return ret;
    }

private:
    QList<T> m_values = {};
    QList<QString> m_roles = {};
    QList<std::function<QVariant(const T&)>> m_getters = {};
    QList<std::function<void(T&, const QVariant&)>> m_setters = {};
};

#endif // OBSERVABLECOLLECTION_H
