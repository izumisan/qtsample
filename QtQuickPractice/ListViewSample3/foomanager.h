#ifndef FOOMANAGER_H
#define FOOMANAGER_H

#include <QObject>
#include <QQmlListProperty>
#include <QDebug>
#include "foo.h"

class FooManager : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QQmlListProperty<Foo> fooList READ fooList NOTIFY listSizeChanged)
public:
    FooManager( QObject* parent = 0 )
        : QObject(parent)
    {}
    FooManager( const FooManager& rhs )
        : m_data(rhs.m_data)
    {
    }

signals:
    void listSizeChanged();

public slots:
    void debugPrint() const
    {
        qDebug() << "size:" << m_data.size();
        for ( auto&& item : m_data )
        {
            qDebug() << item->name();
        }
    }

public:
    QQmlListProperty<Foo> fooList()
    {
        return QQmlListProperty<Foo>( this, this,
                                      &FooManager::appendFoo,
                                      &FooManager::countFoo,
                                      &FooManager::fooAt,
                                      &FooManager::clearFoo );
    }

    void appendFoo( Foo* foo )
    {
        m_data.append( foo );
        emit listSizeChanged();
    }

    int countFoo() const
    {
        return m_data.count();
    }

    Foo* fooAt( int index ) const
    {
        return m_data.at( index );
    }

    void clearFoo()
    {
        m_data.clear();
        emit listSizeChanged();
    }

private:
    static void appendFoo( QQmlListProperty<Foo>* list, Foo* foo )
    {
        reinterpret_cast<FooManager*>( list->data )->appendFoo( foo );
    }
    static int countFoo( QQmlListProperty<Foo>* list )
    {
        return reinterpret_cast<FooManager*>( list->data )->countFoo();
    }
    static Foo* fooAt( QQmlListProperty<Foo>* list, int index )
    {
        return reinterpret_cast<FooManager*>( list->data )->fooAt( index );
    }
    static void clearFoo( QQmlListProperty<Foo>* list )
    {
        reinterpret_cast<FooManager*>( list->data )->clearFoo();
    }

private:
    QList<Foo*> m_data;
};

#endif // FOOMANAGER_H
