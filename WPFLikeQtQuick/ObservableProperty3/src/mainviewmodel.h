#ifndef MAINVIEWMODEL_H
#define MAINVIEWMODEL_H

#include <memory>
#include <QObject>
#include <QDebug>
#include "observableproperty.h"

class MainViewModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY( ObservablePropertyBase* ivalue READ ivalue CONSTANT )
    Q_PROPERTY( ObservablePropertyBase* ivalue2 READ ivalue2 CONSTANT )

public:
    explicit MainViewModel( QObject* parent = nullptr )
        : QObject( parent )
        , m_ivalue( ObservablePropertyHelper<int>::getter(),
                    ObservablePropertyHelper<int>::setter(),
                    parent )
        , m_ivalue2( ObservablePropertyHelper<int>::getter(),
                     parent)
    {
    }
    virtual ~MainViewModel() = default;

public slots:
    void onSubscribe()
    {
        m_actid = m_ivalue.subscribe( [this](const int& value)
        {
            m_ivalue2.setValue( value + 1 );
        } );
    }

    void onUnsubscribe()
    {
        m_ivalue.unsubscribe( m_actid );
        m_actid = 0;
    }

    void printdebug() const
    {
        qDebug() << m_ivalue.value() << m_ivalue2.value();
    }

public:
    ObservableProperty<int>* ivalue() { return &m_ivalue; }
    ObservableProperty<int>* ivalue2() { return &m_ivalue2; }

private:
    ObservableProperty<int> m_ivalue;
    ObservableProperty<int> m_ivalue2;
    int m_actid = 0;
};

#endif // MAINVIEWMODEL_H
