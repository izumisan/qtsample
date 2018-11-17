#ifndef MAINVIEWMODEL_H
#define MAINVIEWMODEL_H

#include <QObject>

class MainViewModel : public QObject
{
    Q_OBJECT

public:
    MainViewModel( QObject* parent = nullptr );
    virtual ~MainViewModel() = default;

public slots:
    void doSomething();
};

#endif // MAINVIEWMODEL_H
