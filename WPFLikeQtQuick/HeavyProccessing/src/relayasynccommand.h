#ifndef RELAYASYNCCOMMAND_H
#define RELAYASYNCCOMMAND_H

#include <functional>
#include <future>
#include <QObject>

namespace viewmodel
{

class RelayAsyncCommand : public QObject
{
    Q_OBJECT
    Q_PROPERTY( bool canExecute READ canExecute NOTIFY canExecuteChanged )
signals:
    void canExecuteChanged() const;
public:
    RelayAsyncCommand( QObject* parent, const std::function<void()>& execute );
    RelayAsyncCommand( QObject* parent, const std::function<void()>& execute, const std::function<bool()>& canExecute );
    virtual ~RelayAsyncCommand() = default;
public slots:
    void execute();
public:
    bool canExecute() const;
public:
    void raiseCanExecute() const;
private:
    bool ready() const;
    void setReady( bool value );

private:
    std::function<void()> m_execute = []{};
    std::function<bool()> m_canExecute = []{ return true; };
    std::future<void> m_future;
    bool m_ready = true;
};

} // namespace viewmodel

#endif // RELAYASYNCCOMMAND_H
