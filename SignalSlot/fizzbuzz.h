#ifndef FIZZBUZZ_H
#define FIZZBUZZ_H

#include <QObject>

class FizzBuzz : public QObject
{
    Q_OBJECT

signals:
    void fizz();
    void buzz();
    void fizzBuzz();
    void valueChanged( const int value );

public:
    void next()
    {
        ++m_value;
        emit valueChanged( m_value );

        fizzBuzzExecute();
    }
    void setValue( const int value )
    {
        if ( m_value != value )
        {
            m_value = value;
            emit valueChanged( m_value );
        }

        fizzBuzzExecute();
    }

private:
    void fizzBuzzExecute()
    {
        if ( m_value % 15 == 0 )
        {
            emit fizzBuzz();
        }
        else if ( m_value % 5 == 0 )
        {
            emit buzz();
        }
        else if ( m_value % 3 == 0 )
        {
            emit fizz();
        }
        else
        {
        }
    }

private:
    int m_value = 0;
};

#endif // FIZZBUZZ_H
