#ifndef MAINVIEWMODEL_H
#define MAINVIEWMODEL_H

#include <memory>
#include <QObject>
#include <QDebug>
#include "observablecollection.h"
#include "foo.h"

class MainViewModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY( ObservableCollectionBase* foos READ foos CONSTANT )
    Q_PROPERTY( ObservableCollectionBase* foos2 READ foos2 CONSTANT )

public:
    explicit MainViewModel( QObject* parent = nullptr )
        : QObject( parent )
        , m_foos( { ObservableCollectionRole<Foo>(
                        "name",
                        [](const Foo& foo){ return foo.name(); } ),
                    ObservableCollectionRole<Foo>(
                        "value",
                        [](const Foo& foo){ return foo.value(); },
                        [](Foo& foo, const QVariant& value){ foo.setValue( value.toInt() ); } )
                  },
                  parent )
    {
//        m_foos = ObservableCollection<Foo>(
//            { ObservableCollectionRole<Foo>(
//                "value",
//                [](const Foo& foo){ return foo.value(); },
//                [](Foo& foo, const QVariant& value){ foo.setValue( value.toInt() ); } )
//            },
//            parent );
        m_foos.add( Foo( "foo1", 1 ) );
        m_foos.add( Foo( "foo2", 2 ) );
        m_foos.add( Foo( "foo3", 3 ) );

        m_foos2 = new ObservableCollection<Foo>(
            { ObservableCollectionRole<Foo>(
                "name",
                [](const Foo& foo){ return foo.name(); } ),
              ObservableCollectionRole<Foo>(
                "value",
                [](const Foo& foo){ return foo.value(); },
                [](Foo& foo, const QVariant& value){ foo.setValue( value.toInt() ); } )
            },
            parent );
        m_foos2->add( Foo( "foo2a", 20 ) );
        m_foos2->add( Foo( "foo2b", 21 ) );
        m_foos2->add( Foo( "foo2c", 22 ) );
    }
    virtual ~MainViewModel() = default;

public slots:

    void printdebug() const
    {
        qDebug() << "size" <<  m_foos.count();
        for ( int i = 0; i < m_foos.count(); ++i )
        {
            auto&& foo = m_foos.value( i );
            qDebug() << foo.name() << foo.value();
        }
    }

public:
    ObservableCollection<Foo>* foos() { return &m_foos; }
    ObservableCollection<Foo>* foos2() { return m_foos2; }

private:
    ObservableCollection<Foo> m_foos;
    ObservableCollection<Foo>* m_foos2 = nullptr;
};

#endif // MAINVIEWMODEL_H
