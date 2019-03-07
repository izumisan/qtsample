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
