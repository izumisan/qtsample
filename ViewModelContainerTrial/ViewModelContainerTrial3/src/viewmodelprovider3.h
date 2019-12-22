#ifndef VIEWMODELPROVIDER3_H
#define VIEWMODELPROVIDER3_H

#include <QObject>
#include "viewmodelcontainer3.h"

class ViewModelProvider3 : public QObject
{
    Q_OBJECT
public:
    explicit ViewModelProvider3( QObject* parent = nullptr )
        : QObject( parent )
    {
    }
    virtual ~ViewModelProvider3() = default;

public slots:
    QObject* get( const QString& key )
    {
        return ViewModelContainer3::instance()->get( key );
    }
};

#endif // VIEWMODELPROVIDER3_H
