#include "observablecollectionbase.h"

ObservableCollectionBase::ObservableCollectionBase( QObject* parent )
    : QAbstractListModel( parent )
{
}

void ObservableCollectionBase::raiseDataChanged( const QModelIndex& topLeft, const QModelIndex& bottomRight, const QVector<int>& roles )
{
    emit dataChanged( topLeft, bottomRight, roles );
    raiseValueChanged( topLeft.row() );
}

void ObservableCollectionBase::raiseValueChanged( const int index ) const
{
    emit valueChanged( index );
}

void ObservableCollectionBase::raiseCollectionChagned( const CollectionChangeAction& action ) const
{
    emit collectionChanged( action );
}
