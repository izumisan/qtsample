#include "foo.h"

Foo::Foo()
{
}

Foo::Foo( const std::string& name, const QColor& color )
    : m_name( name )
    , m_color( color )
{
}

Foo::~Foo()
{
}

std::string Foo::name() const
{
    return m_name;
}

QColor Foo::color() const
{
    return m_color;
}
