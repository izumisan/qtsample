#ifndef FOOENUMCLASS_H
#define FOOENUMCLASS_H

#include <QObject>

namespace foo
{

class FooEnumClass : public QObject
{
    Q_OBJECT
public:
    enum FooEnum
    {
        Foo_1 = 0,
        Foo_2,
        Foo_3
    };

    // Q_ENUMマクロで列挙型をMetaObjectSystemに登録する
    // qmlRegisterUncreatableTypeでFooEnumClassをQMLに公開することにより
    // QML側でFooEnumが使用できる
    // scoped-enum(enum class)も利用可能
    Q_ENUM( FooEnum )
};

}

#endif // FOOENUMCLASS_H
