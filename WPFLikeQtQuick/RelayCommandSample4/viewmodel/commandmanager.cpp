#include <chrono>
#include <QDebug>
#include "commandmanager.h"

namespace viewmodel
{

const std::unique_ptr<CommandManager>& CommandManager::instance()
{
    struct ctor_permission : public CommandManager
    {
        using CommandManager::CommandManager;
    };
    static std::unique_ptr<CommandManager>&& singleton = std::make_unique<ctor_permission>();
    return singleton;
}

CommandManager::~CommandManager()
{
    stop();
}

void CommandManager::timerEvent( QTimerEvent* event )
{
    emit requerySuggested();
}

void CommandManager::start()
{
    if ( m_timerid == 0 )
    {
        m_timerid = startTimer( std::chrono::milliseconds( 50 ) );
    }
}

void CommandManager::stop()
{
    if ( m_timerid != 0 )
    {
        killTimer( m_timerid );
        m_timerid = 0;
    }
}

} // namespace viewmodel
