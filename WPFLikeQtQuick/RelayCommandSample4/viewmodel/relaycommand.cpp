#include "commandmanager.h"
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

    // connectする際に生ポインタが必要になるので、
    // CommandManagerはunique_ptrにしないよう方がよかったかも...
    connect( CommandManager::instance().get(), &CommandManager::requerySuggested,
             this, [this]{raiseCanExecute();},
             Qt::QueuedConnection );

    // 今回は動作確認のため、start()は手動で！
    //CommandManager::instance()->start();
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
