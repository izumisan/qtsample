#ifndef FOO_H
#define FOO_H

#include <QObject>
#include <QString>

class Foo : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString json READ json CONSTANT)

public:
    Foo( QObject* parent = nullptr )
        : QObject( parent )
    {
    }
    virtual ~Foo() = default;
public:
    QString json() const
    {
        return R"({"name": "foo","value": 1.2,"str": "1st\n2nd\n3rd"})";
    }
};

#endif // FOO_H
