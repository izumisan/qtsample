#ifndef BARENUM_H
#define BARENUM_H

#include <QObject>

namespace bar
{

// Q_NAMESPACEマクロで、bar名前空間をMetaObjectSystemに登録する
// 本マクロにより、"staticMetaObject"変数が定義される
Q_NAMESPACE

enum BarEnum
{
    Bar_1 = 0,
    Bar_2,
    Bar_3
};

// Q_ENUM_NSマクロで列挙型をMetaObjectSystemに登録する
// qmlRegisterUncreatableMetaObjectでQ_NAMESPACEで自動定義されたstaticMetaObject変数を
// QMLに公開することによりQML側でBarEnumが利用できる
// scoped-enum(enum class)も利用可能
Q_ENUM_NS( BarEnum )

} // namespace bar

#endif // BARENUM_H
