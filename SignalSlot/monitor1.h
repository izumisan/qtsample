#ifndef MONITOR1_H
#define MONITOR1_H

#include <QObject>
#include <QDebug>

class Monitor1 : public QObject
{
    Q_OBJECT
public slots:
    void fizzMonitor()
    {
        ++m_fizz;
        qDebug() << "[Monitor1] Fizz: " << m_fizz;
    }

    void buzzMonitor()
    {
        ++m_buzz;
        qDebug() << "[Monitor1] Buzz: " << m_buzz;
    }

    void fizzBuzzMonitor()
    {
        ++m_fizzBuzz;
        qDebug() << "[Monitor1] FizzBuzz: " << m_fizzBuzz;
    }

    void outputValue( const int value )
    {
        qDebug() << "[Monitor1] value: " << value;
    }

private:
    int m_fizz = 0;
    int m_buzz = 0;
    int m_fizzBuzz = 0;
};

#endif // MONITOR1_H
