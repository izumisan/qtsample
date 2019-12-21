#ifndef VIEWMODELPROVIDER_H
#define VIEWMODELPROVIDER_H

#include <QObject>
#include "viewmodelcontainer.h"

class ViewModelProvider : public QObject
{
    Q_OBJECT
public:
    explicit ViewModelProvider( QObject* parent = nullptr )
    {
    }
    virtual ~ViewModelProvider() = default;

public slots:
    QObject* viewModel( const QString& key )
    {
//        return ViewModelContainer::instance()->get<QObject>( key ).get();
        return ViewModelContainer::instance()->getA( key );
    }
};

#endif // VIEWMODELPROVIDER_H
