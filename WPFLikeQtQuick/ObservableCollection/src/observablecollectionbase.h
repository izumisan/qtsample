#ifndef OBSERVABLECOLLECTIONBASE_H
#define OBSERVABLECOLLECTIONBASE_H

#include <QAbstractListModel>

class ObservableCollectionBase : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit ObservableCollectionBase( QObject* parent = nullptr );
    virtual ~ObservableCollectionBase() = default;

public:
    virtual int rowCount( const QModelIndex& parent = QModelIndex() ) const override = 0;
    virtual QVariant data( const QModelIndex& index, int role = Qt::DisplayRole ) const override = 0;

protected:
    virtual QHash<int, QByteArray> roleNames() const override = 0;

    virtual void raiseDataChanged( const QModelIndex& topLeft, const QModelIndex& bottomRight, const QVector<int>& roles = QVector<int>() );
};

#endif // OBSERVABLECOLLECTIONBASE_H
