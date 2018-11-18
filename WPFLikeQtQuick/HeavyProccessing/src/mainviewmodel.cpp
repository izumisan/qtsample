#include <QThread>
#include <QDebug>
#include "mainviewmodel.h"


MainViewModel::MainViewModel( QObject* parent )
    : QObject(parent)
{
    m_command = new viewmodel::RelayCommand( parent, [this]{ doSomething(); } );
    m_asyncCommand = new viewmodel::RelayAsyncCommand( parent, [this]{ doSomething(); } );
}

void MainViewModel::doSomething()
{
    qDebug() << __func__ << QThread::currentThreadId() << "wait...";

    QThread::sleep(5);  // 5sec

    qDebug() << __func__ << QThread::currentThreadId() << "complete";
}
