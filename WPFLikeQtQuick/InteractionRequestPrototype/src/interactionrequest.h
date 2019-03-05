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
    void raise( const std::shared_ptr<Confirmation>& context, const std::function<void(const std::shared_ptr<Confirmation>&)>& onClosed );

private:
    std::shared_ptr<Confirmation> m_context = {};
    std::function<void(const std::shared_ptr<Confirmation>&)> m_closedAction = {};
};

#endif // INTERACTIONREQUEST_H
