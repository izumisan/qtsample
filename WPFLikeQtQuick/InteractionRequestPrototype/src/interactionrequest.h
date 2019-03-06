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

public slots:
    virtual void accepted() const { invoke( m_acceptedAction ); }
    virtual void rejected() const { invoke( m_rejectedAction ); }

public:
    void setAcceptedAction( const std::function<void(const std::shared_ptr<Confirmation>&)>& action ) { m_acceptedAction = action; }
    void setRejectedAction( const std::function<void(const std::shared_ptr<Confirmation>&)>& action ) { m_rejectedAction = action; }

    void raise( const std::shared_ptr<Confirmation>& context );
    void raise( const std::shared_ptr<Confirmation>& context,
                const std::function<void(const std::shared_ptr<Confirmation>&)>& acceptedAction );
    void raise( const std::shared_ptr<Confirmation>& context,
                const std::function<void(const std::shared_ptr<Confirmation>&)>& acceptedAction,
                const std::function<void(const std::shared_ptr<Confirmation>&)>& rejectedAction );
private:
    void invoke( const std::function<void(const std::shared_ptr<Confirmation>&)>& action ) const;

private:
    std::shared_ptr<Confirmation> m_context = {};
    std::function<void(const std::shared_ptr<Confirmation>&)> m_acceptedAction = nullptr;
    std::function<void(const std::shared_ptr<Confirmation>&)> m_rejectedAction = nullptr;
};

#endif // INTERACTIONREQUEST_H
