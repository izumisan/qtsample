#ifndef OBSERVABLEPROPERTYBASE_H
#define OBSERVABLEPROPERTYBASE_H

#include <QObject>
#include <QString>

class ObservablePropertyBase : public QObject
{
    Q_OBJECT
    Q_PROPERTY( QString value READ valueProperty WRITE setValueProperty NOTIFY valuePropertyChanged )
signals:
    void valuePropertyChanged() const;

public:
    explicit ObservablePropertyBase( QObject* parent = nullptr );
    virtual ~ObservablePropertyBase() = default;

public:
    virtual QString valueProperty() const = 0;
    virtual void setValueProperty( const QString& value ) = 0;

protected:
    void raiseValuePropertyChanged() const;
};

#endif // OBSERVABLEPROPERTYBASE_H
