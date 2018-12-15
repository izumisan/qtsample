#ifndef VIWEMODELBASE_H
#define VIWEMODELBASE_H

#include <QObject>

class ObservablePropertyBase;

#define OBSERVABLE_PROPERTY( name, var ) \
    Q_PROPERTY( ObservablePropertyBase* name READ get_##var CONSTANT ) \
    ObservablePropertyBase* get_##var() { return &##var; }

class ViewModelBase : public QObject
{
    Q_OBJECT
public:
    explicit ViewModelBase( QObject* parent = nullptr );
    virtual ~ViewModelBase() = default;
};

#endif // VIWEMODELBASE_H
