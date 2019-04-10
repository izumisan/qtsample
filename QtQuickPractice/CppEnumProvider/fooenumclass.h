#ifndef FOOENUMCLASS_H
#define FOOENUMCLASS_H

#include <QObject>

namespace foo
{

class FooEnumClass : public QObject
{
    Q_OBJECT
public:
    enum FooEnum
    {
        Foo_1 = 0,
        Foo_2,
        Foo_3
    };
    Q_ENUM( FooEnum )
};

}

#endif // FOOENUMCLASS_H
