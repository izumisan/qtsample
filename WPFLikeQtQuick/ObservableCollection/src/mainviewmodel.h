#ifndef MAINVIEWMODEL_H
#define MAINVIEWMODEL_H

#include <memory>
#include <QObject>
#include <QDebug>
#include "observablecollection.h"

class MainViewModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY( ObservableCollectionBase* ivalues READ ivalues CONSTANT )

public:
    explicit MainViewModel( QObject* parent = nullptr )
        : QObject( parent )
        , m_ivalues( { 10, 11, 12 },
                     { ObservableCollectionRole<int>( "foo", ObservablePropertyHelper<int>::getter(), nullptr ) },
                     parent )
    {
    }
    virtual ~MainViewModel() = default;

public slots:
    void printdebug() const
    {
        for ( int i = 0; i < m_ivalues.count(); ++i )
        {
            qDebug() << m_ivalues.valueAt( i );
        }
    }

public:
    ObservableCollection<int>* ivalues() { return &m_ivalues; }

private:
    ObservableCollection<int> m_ivalues;
};

#endif // MAINVIEWMODEL_H
