#ifndef BARVIEWMODEL_H
#define BARVIEWMODEL_H

#include <QObject>
#include "viewmodelcontainer.h"
#include "fooviewmodel.h"

class BarViewModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY( int value READ value WRITE setValue NOTIFY valueChanged )
signals:
    void valueChanged( const int value ) const;

public:
    explicit BarViewModel( QObject* parent = nullptr )
        : QObject( parent )
    {
        auto&& foo = ViewModelContainer::instance()->get<FooViewModel>( "fooviewmodel" );
        if ( foo )
        {
            connect( foo.get(),
                     &FooViewModel::valueChanged,
                     this,
                     [this](auto&& value){ setValue( value ); } );
        }
    }

    virtual ~BarViewModel() = default;

public:
    int value() const { return m_value; }
    void setValue( const int& value )
    {
        if ( value != m_value )
        {
            m_value = value;
            emit valueChanged( m_value );
        }
    }

private:
    int m_value = 0;
};

#endif // BARVIEWMODEL_H
