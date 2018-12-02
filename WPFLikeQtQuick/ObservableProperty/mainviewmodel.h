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
        , m_foo2( 20,
                  [](const int& data){ return QString("%1").arg( data ); },
                  parent)
        , m_foo3( 30,
                  [](const int& data){ return QString("%1").arg( data ); },
                  [](int& data, const QString& value){ data = value.toInt(); },
                  parent)
    {
    }
    virtual ~MainViewModel() = default;
public slots:
    void printdebug() const
    {
        qDebug() << m_foo.data() << m_foo2.data() << m_foo3.data();
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
