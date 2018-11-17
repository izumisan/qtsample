#include <QThread>
#include <QDebug>
#include "mainviewmodel.h"


MainViewModel::MainViewModel( QObject* parent )
    : QObject(parent)
{
}

void MainViewModel::doSomething()
{
    qDebug() << __func__ << QThread::currentThreadId() << "wait...";

    QThread::sleep(5);  // 5sec

    qDebug() << __func__ << QThread::currentThreadId() << "complete";
}
