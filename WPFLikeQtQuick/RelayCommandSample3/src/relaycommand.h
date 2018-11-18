#ifndef RELAYCOMMAND_H
#define RELAYCOMMAND_H

#include <functional>
#include <QObject>

namespace viewmodel
{

class RelayCommand : public QObject
{
    Q_OBJECT
    Q_PROPERTY( bool canExecute READ canExecute NOTIFY canExecuteChanged )
signals:
    void canExecuteChanged() const;
public:
    RelayCommand( QObject* parent, const std::function<void()>& execute );
    RelayCommand( QObject* parent, const std::function<void()>& execute, const std::function<bool()>& canExecute );
    virtual ~RelayCommand() = default;
public slots:
    void execute() const;
public:
    bool canExecute() const;
public:
    void raiseCanExecute() const;

private:
    std::function<void()> m_execute = []{};
    std::function<bool()> m_canExecute = []{ return true; };
};

} // namespace viewmodel

#endif // MVVM_RELAYCOMMAND_H
