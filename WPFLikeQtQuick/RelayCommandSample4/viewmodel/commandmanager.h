#ifndef COMMANDMANAGER_H
#define COMMANDMANAGER_H

#include <memory>
#include <QObject>

namespace viewmodel
{

class CommandManager : public QObject
{
    Q_OBJECT
signals:
    void requerySuggested() const;

public:
    static const std::unique_ptr<CommandManager>& instance();

private:
    CommandManager() = default;
public:
    virtual ~CommandManager();

protected:
    void timerEvent( QTimerEvent* event );

public:
    void start();
    void stop();

private:
    int m_timerid = 0;
};

} // namespace viewmodel

#endif // COMMANDMANAGER_H
