#ifndef BAR_H
#define BAR_H

#include <QObject>
#include <QDebug>

class Bar : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int value READ value WRITE setValue NOTIFY valueChanged)

public:
    Bar() {}

signals:
    void valueChanged();

public:

    int value() const
    {
        return m_value;
    }

    void setValue( const int value )
    {
        if ( m_value != (int)value )
        {
            m_value = value;

            emit valueChanged();
        }
    }

private:
    int m_value = 0;
};

#endif // BAR_H
