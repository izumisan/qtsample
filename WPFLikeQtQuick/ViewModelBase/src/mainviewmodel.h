#ifndef MAINVIEWMODEL_H
#define MAINVIEWMODEL_H

#include <QDebug>
#include "viewmodelbase.h"
#include "observableproperty.h"

class MainViewModel : public ViewModelBase
{
    Q_OBJECT
    OBSERVABLE_PROPERTY( ivalue, m_ivalue )
    OBSERVABLE_PROPERTY( dvalue, m_dvalue )

public:
    explicit MainViewModel( QObject* parent = nullptr )
        : ViewModelBase( parent )
        , m_ivalue( 123,
                   ObservablePropertyHelper<int>::getter(),
                   ObservablePropertyHelper<int>::setter(),
                   parent )
        , m_dvalue( 100.0,
                    ObservablePropertyHelper<double>::getter(),
                    ObservablePropertyHelper<double>::setter(),
                    parent )
    {
    }

    virtual ~MainViewModel() = default;

public slots:
    void onClicked1()
    {
        setProperty( m_ivalue, m_ivalue.value() + 1, [this]{ printdebug(); } );
    }

    void onClicked2()
    {
        setProperty( m_dvalue, m_dvalue.value() * 1.01, [this]{ printdebug(); } );
    }

    void printdebug() const
    {
        qDebug() << m_ivalue.value() << m_dvalue.value();
    }

private:
    ObservableProperty<int> m_ivalue;
    ObservableProperty<double> m_dvalue;
};

#endif // MAINVIEWMODEL_H
