#ifndef FIZZBUZZ_H
#define FIZZBUZZ_H

#include <QObject>
#include <QString>
#include <QVariant>

class FizzBuzz : public QObject
{
    Q_OBJECT
public:
    FizzBuzz() = default;

signals:
    void updated( QVariant text );  // updatedシグナル

public slots:
    void next()
    {
        ++m_value;
        m_current = fizzBuzz( m_value );
        emit updated( QVariant( m_current ) );  // updatedシグナルの発行
    }

private:
    QString fizzBuzz( const int value ) const
    {
        auto&& ret = QString();
        if ( value % 15 == 0 )
        {
            ret = "FizzBuzz";
        }
        else if ( value % 5 == 0 )
        {
            ret = "Buzz";
        }
        else if ( value % 3 == 0 )
        {
            ret = "Fizz";
        }
        else
        {
            ret = QString( "%1" ).arg( value );
        }
        return ret;
    }

private:
    int m_value = 0;
    QString m_current = "";
};

#endif // FIZZBUZZ_H
