import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.3

// C++で定義したFooクラスのインポート
import FooLibrary 1.0

Window {
    visible: true
    width: 300
    height: 200
    title: qsTr("Property Binding 3")

    Foo {
        id: foo
    }

    Column {
        anchors.centerIn: parent

        Text {
            font.pixelSize: 20
            anchors.horizontalCenter: parent.horizontalCenter

            // model -> view
            Binding on text {
                value: foo.value
            }
        }

        Slider {
            id: slider
            from: -100.0
            to:  100.0
            anchors.horizontalCenter: parent.horizontalCenter

            // view -> model
            Binding {
                target: foo
                property: "value"
                value: slider.value
            }

            // Slider.valueをFoo.valueにバインドすると
            // バインディングループになってしてしまう
            //Binding on value {
            //    value: foo.value
            //}
            Component.onCompleted: {
                value = foo.value
            }
        }
    }

    Component.onCompleted: {
        foo.value = 88
    }
}
