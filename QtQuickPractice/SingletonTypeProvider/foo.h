#ifndef FOO_H
#define FOO_H

#include <QObject>
#include <QDebug>
#include "bar.h"

class Foo : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(Foo)

    Q_PROPERTY(Bar* bar READ bar CONSTANT FINAL )

public:
    Foo() : m_bar(){}

public:
    Bar* bar()
    {
        return &m_bar;
    }

private:
    Bar m_bar;
};

#endif // FOO_H
