#ifndef FOO_H
#define FOO_H

#include <QObject>
#include <QString>

class Foo : public QObject
{
    Q_OBJECT
public:
    // QMLからアクセスできるようにするためQ_INVOKABLEマクロを付与する
    Q_INVOKABLE QString message() const
    {
        return "This message is Foo::message()";
    }
};

#endif // FOO_H
