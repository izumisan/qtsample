#ifndef OBSERVABLECOLLECTION_H
#define OBSERVABLECOLLECTION_H

#include <functional>
#include <algorithm>
#include "observablecollectionbase.h"
#include "observablecollectionrole.h"
#include "observablepropertyhelper.h"
#include <QDebug>
template<class T>
class ObservableCollection : public ObservableCollectionBase
{
public:
    ObservableCollection( QObject* parent = nullptr )
        : ObservableCollectionBase( parent )
    {
    }
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
            add( x );
        }
    }
    virtual ~ObservableCollection() = default;

//    ObservableCollection( const ObservableCollection<T>& ) = default;
//    ObservableCollection<T>& operator = ( const ObservableCollection<T>& ) = default;

public:
//    using const_iterator = QList<T>::const_iterator;
//    const_iterator cbegin() const { return m_values.cbegin(); }
//    const_iterator cend() const { return m_values.cend(); }

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
                if ( getter )
                {
                    ret = getter( m_values.at( index.row() ) );
                }
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
                //if ( m_values.at( index.row() ) != value )
                if ( data( index, role ) != value )
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
    void add( const T& value )
    {
        beginInsertRows( QModelIndex(), rowCount(), rowCount() );
        m_values.append( value );
        endInsertRows();

        raiseCollectionChagned( CollectionChangeAction::Add );
    }
    void remove ( const T& value )
    {
        auto&& it = std::find( m_values.cbegin(), m_values.cend(), value );
        if ( it != m_values.cend() )
        {
            auto&& removeIndex = it - m_values.cbegin();
            removeAt( removeIndex );
        }
    }
    void removeAt( const int pos )
    {
        beginRemoveRows( QModelIndex, pos, pos );
        m_values.removeAt( pos );
        endRemoveRows();

        raiseCollectionChagned( CollectionChangeAction::Remove );
    }
    void clear()
    {
        beginResetModel();
        m_values.clear();
        endResetModel();

        raiseCollectionChagned( CollectionChangeAction::Reset );
    }
    T value( const int& index ) const { return m_values.at( index ); }
    QList<T> values() const { return m_values; }
    bool setValue( const int pos, const T& value, bool doesRaseDataChanged = true )
    {
        bool ret = false;
        if ( ( 0 <= pos ) && ( pos < m_values.size() ) )
        {
            if ( m_values.at( pos ) != value )
            {
                m_values[ pos ] = value;
                ret = true;

                if ( doesRaseDataChanged )
                {
                    raiseDataChanged( index( pos ), index( pos ), roleNames().keys() );
                }
            }
        }
        return ret;
    }
    int count() const { return m_values.count(); }

private:
    constexpr int roleOffset() const { return Qt::UserRole + 1; }

private:
    QList<T> m_values = {};
    QList<ObservableCollectionRole<T>> m_roles = {};
};

#endif // OBSERVABLECOLLECTION_H
