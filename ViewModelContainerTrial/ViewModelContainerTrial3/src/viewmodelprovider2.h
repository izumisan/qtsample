#ifndef VIEWMODELPROVIDER2_H
#define VIEWMODELPROVIDER2_H

#include <QObject>
#include "viewmodelcontainer2.h"
#include "fooviewmodel.h"
#include "barviewmodel.h"

class ViewModelProvider2 : public QObject
{
    Q_OBJECT
public:
    explicit ViewModelProvider2( QObject* parent = nullptr )
        : QObject( parent )
    {
    }
    virtual ~ViewModelProvider2() = default;

public slots:
    QObject* getFromSharedPtr( const QString& key )
    {
        // これは例外が発生する
        // std::any_cast で std::shared_ptr<ViewModelType> から std::shared_ptr<QObject> を取り出せない
        return ViewModelContainer2::instance()->getSharedPtr<QObject>( key ).get();
    }

    QObject* getFromPtr( const QString& key )
    {
        // これも例外が発生する
        // std::any_cast で ViewModelType* から QObject* を取り出せない
        return ViewModelContainer2::instance()->getPtr<QObject>( key );
    }

    QObject* fooViewModel()
    {
        return ViewModelContainer2::instance()->getSharedPtr<FooViewModel>( "FooViewModel" ).get();
    }

    QObject* barViewModel()
    {
        return ViewModelContainer2::instance()->getPtr<BarViewModel>( "BarViewModel" );
    }
};

#endif // VIEWMODELPROVIDER2_H
