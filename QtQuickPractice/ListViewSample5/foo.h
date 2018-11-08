#ifndef FOO_H
#define FOO_H

#include <string>
#include <QColor>

class Foo
{
public:
    Foo();
    Foo( const std::string& name, const QColor& color );
    virtual ~Foo();
public:
    std::string name() const;
    QColor color() const;

private:
    std::string m_name = "black";
    QColor m_color = Qt::black;
};

#endif // FOO_H
