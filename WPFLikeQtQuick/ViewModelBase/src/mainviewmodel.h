#ifndef MAINVIEWMODEL_H
#define MAINVIEWMODEL_H

#include <QDebug>
#include "viewmodelbase.h"
#include "observableproperty.h"

class MainViewModel : public ViewModelBase
{
    Q_OBJECT
    OBSERVABLE_PROPERTY( value, m_value )

public:
    explicit MainViewModel( QObject* parent = nullptr )
        : ViewModelBase( parent )
        , m_value( 123,
                   ObservablePropertyHelper<int>::getter(),
                   ObservablePropertyHelper<int>::setter(),
                   parent )
    {
    }

    virtual ~MainViewModel() = default;

public slots:

    void printdebug() const
    {
        qDebug() << m_value.value();
    }

private:
    ObservableProperty<int> m_value;
};

#endif // MAINVIEWMODEL_H
