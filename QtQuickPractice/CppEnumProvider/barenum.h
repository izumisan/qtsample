#ifndef BARENUM_H
#define BARENUM_H

#include <QObject>

namespace bar
{

Q_NAMESPACE

enum BarEnum
{
    Bar_1 = 0,
    Bar_2,
    Bar_3
};

Q_ENUM_NS( BarEnum )

} // namespace bar

#endif // BARENUM_H
