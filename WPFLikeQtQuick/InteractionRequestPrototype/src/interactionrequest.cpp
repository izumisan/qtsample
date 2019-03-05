#include "interactionrequest.h"

InteractionRequest::InteractionRequest( QObject* parent )
    : QObject( parent )
{
}

void InteractionRequest::raise( const std::shared_ptr<Confirmation>& context )
{
    raise( context, [](const std::shared_ptr<Confirmation>&){} );
}

void InteractionRequest::raise( const std::shared_ptr<Confirmation>& context, const std::function<void(const std::shared_ptr<Confirmation>&)>& onClosed )
{
    m_context = context;
    emit contextChanged();

    m_closedAction = onClosed;

    if ( m_context )
    {
        connect( m_context.get(),
                 &Confirmation::done,
                 this,
                 [this]
        {
            if ( m_closedAction != nullptr )
            {
                m_closedAction( m_context );
            }
        } );

        emit raised();
    }
}
