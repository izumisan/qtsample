#include "confirmation.h"

Confirmation::Confirmation( QObject* parent )
    : Confirmation( {}, {}, parent )
{
}

Confirmation::Confirmation( const QString& title, QObject* parent )
    : Confirmation( title, {}, parent )
{
}

Confirmation::Confirmation( const QString& title, const QVariant& content, QObject* parent )
    : QObject( parent )
    , m_title( title )
    , m_content( content )
{
}

QString Confirmation::title() const
{
    return m_title;
}

void Confirmation::setTitle( const QString& value )
{
    if ( m_title != value )
    {
        m_title = value;
        emit titleChanged();
    }
}

QVariant Confirmation::content() const
{
    return m_content;
}

void Confirmation::setContent( const QVariant& value )
{
    if ( m_content != value )
    {
        m_content = value;
        emit contentChanged();
    }
}

bool Confirmation::confirmed() const
{
    return m_confirmed;
}

void Confirmation::close( const int resultCode )
{
    if ( resultCode != 0 )
    {
        m_confirmed = true;
    }
    else
    {
        m_confirmed = false;
    }

    emit done( resultCode );
}
