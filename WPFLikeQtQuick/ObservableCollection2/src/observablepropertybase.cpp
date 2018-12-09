#include "observablepropertybase.h"

ObservablePropertyBase::ObservablePropertyBase( QObject* parent )
    : QObject(parent)
{
}

void ObservablePropertyBase::raiseValuePropertyChanged() const
{
    emit valuePropertyChanged();
}
