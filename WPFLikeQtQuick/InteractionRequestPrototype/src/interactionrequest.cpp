#include "interactionrequest.h"

InteractionRequest::InteractionRequest( QObject* parent )
    : QObject( parent )
{
}

void InteractionRequest::raise( const std::shared_ptr<Confirmation>& context )
{
    m_context = context;
    emit contextChanged();

    emit raised();
}

void InteractionRequest::raise( const std::shared_ptr<Confirmation>& context,
                                const std::function<void(const std::shared_ptr<Confirmation>&)>& acceptedAction )
{
    setAcceptedAction( acceptedAction );
    raise( context );
}

void InteractionRequest::raise( const std::shared_ptr<Confirmation>& context,
                                const std::function<void(const std::shared_ptr<Confirmation>&)>& acceptedAction,
                                const std::function<void(const std::shared_ptr<Confirmation>&)>& rejectedAction )
{
    setAcceptedAction( acceptedAction );
    setRejectedAction( rejectedAction );
    raise( context );
}

void InteractionRequest::invoke( const std::function<void(const std::shared_ptr<Confirmation>&)>& action ) const
{
    if ( action )
    {
        action( m_context );
    }
}
