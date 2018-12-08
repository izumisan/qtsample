#ifndef OBSERVABLECOLLECTIONBASE_H
#define OBSERVABLECOLLECTIONBASE_H

#include <QAbstractListModel>

enum class CollectionChangeAction
{
    Add,
    Remove,
    Reset
};

class ObservableCollectionBase : public QAbstractListModel
{
    Q_OBJECT
signals:
    void valueChanged( int index ) const;
    void collectionChanged( CollectionChangeAction action ) const;

public:
    explicit ObservableCollectionBase( QObject* parent = nullptr );
    virtual ~ObservableCollectionBase() = default;
//    ObservableCollectionBase( const ObservableCollectionBase& ) = default;
//    ObservableCollectionBase& operator = ( const ObservableCollectionBase& ) = default;

public:
    virtual int rowCount( const QModelIndex& parent = QModelIndex() ) const override = 0;
    virtual QVariant data( const QModelIndex& index, int role = Qt::DisplayRole ) const override = 0;

protected:
    virtual QHash<int, QByteArray> roleNames() const override = 0;

    virtual void raiseDataChanged( const QModelIndex& topLeft, const QModelIndex& bottomRight, const QVector<int>& roles = QVector<int>() );
    virtual void raiseValueChanged( const int index ) const;
    virtual void raiseCollectionChagned( const CollectionChangeAction& action ) const;
};

#endif // OBSERVABLECOLLECTIONBASE_H
