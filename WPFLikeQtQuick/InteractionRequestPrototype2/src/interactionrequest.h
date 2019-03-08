#ifndef INTERACTIONREQUEST_H
#define INTERACTIONREQUEST_H

#include <functional>
#include <QObject>
#include "confirmation.h"

class InteractionRequest : public QObject
{
    Q_OBJECT
    Q_PROPERTY( Confirmation* context READ context NOTIFY contextChanged )
signals:
    void contextChanged() const;
    void raised() const;

public:
    explicit InteractionRequest( QObject* parent = nullptr );
    virtual ~InteractionRequest() = default;

public:
    Confirmation* context() const { return m_context.get(); }

public:
    void raise( const std::shared_ptr<Confirmation>& context );

private:
    std::shared_ptr<Confirmation> m_context = {};
};

#endif // INTERACTIONREQUEST_H
