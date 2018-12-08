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
    ObservableCollection( const QList<ObservableCollectionRole<T>>& roles,
                          QObject* parent = nullptr )
        : ObservableCollection( {}, roles, parent )
    {
    }
    ObservableCollection( const QList<T>& values,
                          const QList<ObservableCollectionRole<T>>& roles,
                          QObject* parent = nullptr )
        : ObservableCollectionBase( parent )
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
        auto&& ret = QVariant();
        if ( index.isValid() )
        {
            auto&& roleIndex = role - roleOffset();
            if ( ( 0 <= roleIndex ) && ( roleIndex < m_roles.size() ) )
            {
                auto&& getter = m_roles.at( roleIndex ).getter();
                ret = getter( m_values.at( index.row() ) );
            }
        }
        return ret;
    }
    virtual bool setData( const QModelIndex& index, const QVariant& value, int role = Qt::EditRole ) override
    {
        bool ret = false;
        if ( index.isValid() )
        {
            auto&& roleIndex = role - roleOffset();
            if ( ( 0 <= roleIndex ) && ( roleIndex < m_roles.size() ) )
            {
                if ( m_values.at( index.row() ) != value )
                {
                    auto&& setter = m_roles.at( roleIndex ).setter();
                    if ( setter )
                    {
                        setter( m_values[ index.row() ], value );
                        ret = true;

                        raiseDataChanged( index, index, { role } );
                    }
                }
            }
        }
        return ret;
    }

protected:
    virtual QHash<int, QByteArray> roleNames() const override
    {
        QHash<int, QByteArray> ret {};
        for ( int i = 0; i < m_roles.size(); ++i )
        {
            auto&& role = roleOffset() + i;
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
    T value( const int& index ) const { return m_values.at( index ); }
    int count() const { return m_values.count(); }

private:
    constexpr int roleOffset() const { return Qt::UserRole + 1; }

private:
    QList<T> m_values = {};
    QList<ObservableCollectionRole<T>> m_roles = {};
};

#endif // OBSERVABLECOLLECTION_H
