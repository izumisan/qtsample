#ifndef OBSERVABLEPROPERTYBASE_H
#define OBSERVABLEPROPERTYBASE_H

#include <QObject>
#include <QVariant>

class ObservablePropertyBase : public QObject
{
    Q_OBJECT
    Q_PROPERTY( QVariant value READ valueProperty WRITE setValueProperty NOTIFY valuePropertyChanged )
signals:
    void valuePropertyChanged() const;

public:
    explicit ObservablePropertyBase( QObject* parent = nullptr );
    virtual ~ObservablePropertyBase() = default;

public:
    virtual QVariant valueProperty() const = 0;
    virtual void setValueProperty( const QVariant& value ) = 0;

public:
    virtual void raiseValuePropertyChanged() const;
};

#endif // OBSERVABLEPROPERTYBASE_H
