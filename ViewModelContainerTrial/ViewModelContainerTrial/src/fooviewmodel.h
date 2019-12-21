#ifndef FOOVIEWMODEL_H
#define FOOVIEWMODEL_H

#include <QObject>

class FooViewModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY( int value READ value WRITE setValue NOTIFY valueChanged )
signals:
    void valueChanged( const int value ) const;

public:
    explicit FooViewModel( QObject* parent = nullptr )
        : QObject( parent )
    {
    }

    virtual ~FooViewModel() = default;

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

#endif // FOOVIEWMODEL_H
