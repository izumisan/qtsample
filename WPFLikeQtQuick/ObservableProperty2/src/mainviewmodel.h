#ifndef MAINVIEWMODEL_H
#define MAINVIEWMODEL_H

#include <memory>
#include <QObject>
#include <QDebug>
#include "observableproperty.h"
#include "observablepropertyhelper.h"
#include "foo.h"

class MainViewModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY( ObservablePropertyBase* str READ str CONSTANT )
    Q_PROPERTY( ObservablePropertyBase* ivalue READ ivalue CONSTANT )
    Q_PROPERTY( ObservablePropertyBase* dvalue READ dvalue CONSTANT )
    Q_PROPERTY( ObservablePropertyBase* foo1name READ foo1name CONSTANT )
    Q_PROPERTY( ObservablePropertyBase* foo1value READ foo1value CONSTANT )
    Q_PROPERTY( ObservablePropertyBase* foo2name READ foo2name CONSTANT )
    Q_PROPERTY( ObservablePropertyBase* foo2value READ foo2value CONSTANT )

public:
    explicit MainViewModel( QObject* parent = nullptr )
        : QObject( parent )
        , m_str( "str",
                 ObservablePropertyHelper<QString>::getter(),
                 ObservablePropertyHelper<QString>::setter(),
                 parent )
        , m_ivalue( 20,
                  ObservablePropertyHelper<int>::getter(),
                  ObservablePropertyHelper<int>::setter(),
                  parent)
        , m_dvalue( 1.23,
                  ObservablePropertyHelper<double>::getter(),
                  ObservablePropertyHelper<double>::setter(),
                  parent)
        , m_foo1n( {},
                  [](const Foo* foo){ return foo->name(); },
                  [](Foo*& foo, const QVariant& value){ foo->setName( value.toString() ); },
                  parent)
        , m_foo1v( {},
                  [](const Foo* foo){ return foo->value(); },
                  [](Foo*& foo, const QVariant& value){ foo->setValue( value.toInt() ); },
                  parent)
        , m_foo2n( {},
                  [](const std::shared_ptr<Foo>& foo){ return foo->name(); },
                  [](std::shared_ptr<Foo>& foo, const QVariant& value){ foo->setName( value.toString() ); },
                  parent)
        , m_foo2v( {},
                  [](const std::shared_ptr<Foo>& foo){ return foo->value(); },
                  [](std::shared_ptr<Foo>& foo, const QVariant& value){ foo->setValue( value.toInt() ); },
                  parent)
    {
        Foo* foo1 = new Foo();  // fooのdeleteは省略
        foo1->setName( "foo1" );
        foo1->setValue( 11 );

        // プロパティは2つだが、実体はfoo1のみ
        m_foo1n.setValue( foo1 );
        m_foo1v.setValue( foo1 );


        auto&& foo2 = std::make_shared<Foo>();
        foo2->setName( "foo2" );
        foo2->setValue( 22 );

        // プロパティは2つだが、実体はfoo2のみ
        m_foo2n.setValue( foo2 );
        m_foo2v.setValue( foo2 );
    }
    virtual ~MainViewModel() = default;
public slots:
    void printdebug() const
    {
        qDebug() << m_str.value()
                 << m_ivalue.value()
                 << m_dvalue.value();
        qDebug() << m_foo1n.value()->name() << m_foo1n.value()->value()
                 << m_foo1v.value()->name() << m_foo1v.value()->value();
        qDebug() << m_foo2n.value()->name() << m_foo2n.value()->value()
                 << m_foo2v.value()->name() << m_foo2v.value()->value();
    }

public:
    ObservableProperty<QString>* str() { return &m_str; }
    ObservableProperty<int>* ivalue() { return &m_ivalue; }
    ObservableProperty<double>* dvalue() { return &m_dvalue; }
    ObservableProperty<Foo*>* foo1name() { return &m_foo1n; }
    ObservableProperty<Foo*>* foo1value() { return &m_foo1v; }
    ObservableProperty<std::shared_ptr<Foo>>* foo2name() { return &m_foo2n; }
    ObservableProperty<std::shared_ptr<Foo>>* foo2value() { return &m_foo2v; }

private:
    ObservableProperty<QString> m_str;
    ObservableProperty<int> m_ivalue;
    ObservableProperty<double> m_dvalue;
    ObservableProperty<Foo*> m_foo1n;
    ObservableProperty<Foo*> m_foo1v;
    ObservableProperty<std::shared_ptr<Foo>> m_foo2n;
    ObservableProperty<std::shared_ptr<Foo>> m_foo2v;
};

#endif // MAINVIEWMODEL_H
