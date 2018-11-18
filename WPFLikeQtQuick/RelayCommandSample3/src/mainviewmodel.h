#ifndef MAINVIEWMODEL_H
#define MAINVIEWMODEL_H

#include <QObject>
#include "relaycommand.h"
#include "relayasynccommand.h"

class MainViewModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY( viewmodel::RelayCommand* relayCommand READ relayCommand CONSTANT )
    Q_PROPERTY( viewmodel::RelayAsyncCommand* asyncCommand READ asyncCommand CONSTANT )

public:
    MainViewModel( QObject* parent = nullptr );
    virtual ~MainViewModel() = default;

public slots:
    void doSomething();

public:
    viewmodel::RelayCommand* relayCommand() const
    {
        return m_command;
    }
    viewmodel::RelayAsyncCommand* asyncCommand() const
    {
        return m_asyncCommand;
    }

private:
    viewmodel::RelayCommand* m_command;
    viewmodel::RelayAsyncCommand* m_asyncCommand;
};

#endif // MAINVIEWMODEL_H
