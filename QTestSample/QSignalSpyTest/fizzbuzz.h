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

public:
    void exec( const int value )
    {
        if ( value % 15 == 0 )
        {
            emit fizzBuzz();
        }
        else if ( value % 5 == 0 )
        {
            emit buzz();
        }
        else if ( value % 3 == 0 )
        {
            emit fizz();
        }
        else
        {
        }
    }
};

#endif // FIZZBUZZ_H
