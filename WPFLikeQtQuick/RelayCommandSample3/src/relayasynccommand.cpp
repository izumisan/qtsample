#include "relayasynccommand.h"

namespace viewmodel
{

RelayAsyncCommand::RelayAsyncCommand( QObject* parent, const std::function<void()>& execute )
    : QObject(parent)
    , m_execute(execute)
{
    assert( m_execute != nullptr );
}

RelayAsyncCommand::RelayAsyncCommand( QObject* parent, const std::function<void()>& execute, const std::function<bool()>& canExecute )
    : QObject(parent)
    , m_execute(execute)
    , m_canExecute(canExecute)
{
    assert( m_execute != nullptr );
    assert( m_canExecute != nullptr );
}

void RelayAsyncCommand::execute()
{
    setReady( false );
    m_future = std::async( std::launch::async,
    [this]
    {
        m_execute();
        setReady( true );
    } );
}

bool RelayAsyncCommand::canExecute() const
{
    return ready() ?  m_canExecute() : false;
}

void RelayAsyncCommand::raiseCanExecute() const
{
    emit canExecuteChanged();
}

bool RelayAsyncCommand::ready() const
{
    return m_ready;
}

void RelayAsyncCommand::setReady( bool value )
{
    if ( m_ready != value )
    {
        m_ready = value;

        raiseCanExecute();
    }
}

} // namespace viewmodel
