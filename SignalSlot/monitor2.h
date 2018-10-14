#ifndef MONITOR2_H
#define MONITOR2_H

#include <QObject>
#include <QDebug>

class Monitor2 : public QObject
{
    Q_OBJECT
public:
    void fizzMonitor()
    {
        ++m_fizz;
        qDebug() << "[Monitor2] Fizz: " << m_fizz;
    }

    void buzzMonitor()
    {
        ++m_buzz;
        qDebug() << "[Monitor2] Buzz: " << m_buzz;
    }

    void fizzBuzzMonitor()
    {
        ++m_fizzBuzz;
        qDebug() << "[Monitor2] FizzBuzz: " << m_fizzBuzz;
    }

    void outputValue( const int value )
    {
        qDebug() << "[Monitor2] value: " << value;
    }

private:
    int m_fizz = 0;
    int m_buzz = 0;
    int m_fizzBuzz = 0;
};

#endif // MONITOR2_H
