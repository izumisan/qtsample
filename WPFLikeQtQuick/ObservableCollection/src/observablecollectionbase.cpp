#include "observablecollectionbase.h"

ObservableCollectionBase::ObservableCollectionBase( QObject* parent )
    : QAbstractListModel( parent )
{
}

void ObservableCollectionBase::raiseDataChanged( const QModelIndex& topLeft, const QModelIndex& bottomRight, const QVector<int>& roles )
{
    emit dataChanged( topLeft, bottomRight, roles );
}
