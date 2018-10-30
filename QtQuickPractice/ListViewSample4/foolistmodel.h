#ifndef FOOLISTMODEL_H
#define FOOLISTMODEL_H

#include <QObject>
#include <QAbstractListModel>
#include <QList>
#include "foo.h"

class FooListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum class FooRole
    {
        NameRole = Qt::UserRole + 1,
        ColorRole,
        CountRole
    };
public:
    FooListModel( QObject* parent = nullptr );

public:
    void add( const Foo& foo );

    Q_INVOKABLE void removeFirst();
    Q_INVOKABLE void pushBack();

public:
    int rowCount( const QModelIndex& parent = QModelIndex() ) const override;
    QVariant data( const QModelIndex& index, int role = Qt::DisplayRole ) const override;

protected:
    QHash<int, QByteArray> roleNames() const override;

private:
    QList<Foo> m_data;
};

#endif // FOOLISTMODEL_H
