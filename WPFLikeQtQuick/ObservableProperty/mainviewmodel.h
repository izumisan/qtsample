#ifndef MAINVIEWMODEL_H
#define MAINVIEWMODEL_H

#include <QObject>
#include "observableproperty.h"

class MainViewModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY( ObservablePropertyBase* foo READ foo CONSTANT )
    Q_PROPERTY( ObservablePropertyBase* foo2 READ foo2 CONSTANT )

public:
    explicit MainViewModel( QObject* parent = nullptr )
        : QObject( parent )
        , m_foo( "foo", parent )
        , m_foo2( 10,
                  [](const int& data){ return QString("%1").arg( data ); },
                  parent)
    {
    }
    virtual ~MainViewModel() = default;

public:
    ObservableProperty<QString>* foo() { return &m_foo; }
    ObservableProperty<int>* foo2() { return &m_foo2; }

private:
    ObservableProperty<QString> m_foo;
    ObservableProperty<int> m_foo2;
};

#endif // MAINVIEWMODEL_H
