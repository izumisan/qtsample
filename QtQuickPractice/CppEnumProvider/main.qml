import QtQuick 2.12
import QtQuick.Window 2.12
import viewmodel 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("CppEnumProvider")

    Component.onCompleted: {
        console.log( FooEnum.Foo_1 )
        console.log( FooEnum.Foo_2 )
        console.log( FooEnum.Foo_3 )

        console.log( Bar.Bar_1 )
        console.log( Bar.Bar_2 )
        console.log( Bar.Bar_3 )
    }
}
