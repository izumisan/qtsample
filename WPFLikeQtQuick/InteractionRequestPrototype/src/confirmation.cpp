#include <QDebug>
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

int Confirmation::resultCode() const
{
    return m_resultCode;
}

void Confirmation::setResultCode( const int& value )
{
    if ( m_resultCode != value )
    {
        m_resultCode = value;
        emit resultCodeChanged();
    }
}

bool Confirmation::isAccepted() const
{
    return ( m_resultCode == 1 );
}

bool Confirmation::isRejected() const
{
    return ( m_resultCode == 0 );
}

void Confirmation::invoke( const std::function<void()>& action ) const
{
    if ( action )
    {
        action();
    }
}
