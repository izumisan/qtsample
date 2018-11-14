#include "relaycommand.h"

namespace viewmodel
{

RelayCommand::RelayCommand( QObject* parent, const std::function<void()>& execute )
    : QObject(parent)
    , m_execute(execute)
{
    assert( m_execute != nullptr );
}

RelayCommand::RelayCommand( QObject* parent, const std::function<void()>& execute, const std::function<bool()>& canExecute )
    : QObject(parent)
    , m_execute(execute)
    , m_canExecute(canExecute)
{
    assert( m_execute != nullptr );
    assert( m_canExecute != nullptr );
}

void RelayCommand::execute() const
{
    m_execute();
}

bool RelayCommand::canExecute() const
{
    return m_canExecute();
}

void RelayCommand::raiseCanExecute() const
{
    emit canExecuteChanged();
}

} // namespace viewmodel
