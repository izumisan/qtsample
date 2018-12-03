#ifndef MAINVIEWMODEL_H
#define MAINVIEWMODEL_H

#include <QObject>
#include <QDebug>
#include "observableproperty.h"

class MainViewModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY( ObservablePropertyBase* foo READ foo CONSTANT )
    Q_PROPERTY( ObservablePropertyBase* foo2 READ foo2 CONSTANT )
    Q_PROPERTY( ObservablePropertyBase* foo3 READ foo3 CONSTANT )

public:
    explicit MainViewModel( QObject* parent = nullptr )
        : QObject( parent )
        , m_foo( "foo", parent )
        , m_foo2( 20, parent)
        , m_foo3( 30,
                  [](const int& value){ return value; },
                  [](int& value, const QVariant& newValue){ value = newValue.toInt(); },
                  parent)
    {
    }
    virtual ~MainViewModel() = default;
public slots:
    void printdebug() const
    {
        qDebug() << m_foo.value() << m_foo2.value() << m_foo3.value();
    }

public:
    ObservableProperty<QString>* foo() { return &m_foo; }
    ObservableProperty<int>* foo2() { return &m_foo2; }
    ObservableProperty<int>* foo3() { return &m_foo3; }

private:
    ObservableProperty<QString> m_foo;
    ObservableProperty<int> m_foo2;
    ObservableProperty<int> m_foo3;
};

#endif // MAINVIEWMODEL_H
