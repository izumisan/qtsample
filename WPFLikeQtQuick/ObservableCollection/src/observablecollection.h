#ifndef OBSERVABLECOLLECTION_H
#define OBSERVABLECOLLECTION_H

#include <functional>
#include "observablecollectionbase.h"
#include "observablecollectionrole.h"
#include "observablepropertyhelper.h"
#include <QDebug>
template<class T>
class ObservableCollection : public ObservableCollectionBase
{
public:
    ObservableCollection( const QList<T>& values,
                          const QList<ObservableCollectionRole<T>>& roles,
                          QObject* parent = nullptr )
        : ObservableCollectionBase( parent )
//        , m_values( values )
        , m_roles( roles )
    {
        for ( auto&& x: values )
        {
            append( x );
        }
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
        qDebug() << __func__;
        auto&& ret = QVariant();
        if ( index.isValid() )
        {
            constexpr int roleOffset = Qt::UserRole + 1;
            auto&& roleIndex = role - roleOffset;
            if ( ( 0 <= roleIndex ) && ( roleIndex < m_roles.size() ) )
            {
                auto&& getter = m_roles.at( roleIndex ).getter();
                ret = getter( m_values.at( index.row() ) );

                qDebug() << role << index.row() << ret;
            }
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
            ret.insert( role, m_roles.at( i ).roleName().toStdString().c_str() );
        }
        return ret;
    }

public:
    void append( const T& value )
    {
        beginInsertRows( QModelIndex(), rowCount(), rowCount() );
        m_values.append( value );
        endInsertRows();
    }
    T valueAt( const int& index ) const { return m_values.at( index ); }
    int count() const { return m_values.count(); }

private:
    QList<T> m_values = {};
    QList<ObservableCollectionRole<T>> m_roles = {};
};

#endif // OBSERVABLECOLLECTION_H
