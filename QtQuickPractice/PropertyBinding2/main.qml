import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.3

// C++で定義したFooクラスのインポート
import FooLibrary 1.0

Window {
    visible: true
    width: 300
    height: 200
    title: qsTr("Property Binding 2")

    // Fooクラス（Fooエレメント）のインスタンス化
    // #1
    Foo {
        id: foodata1
        value: -25
    }
    // #2
    Foo {
        id: foodata2
        value: 25
    }

    Column {
        anchors.centerIn: parent

        Text {
            text: foodata1.value  // #1
            font.pixelSize: 20
            anchors.horizontalCenter: parent.horizontalCenter
        }

        Slider {
            value: foodata1.value  // #1
            from: -100.0
            to:  100.0
            anchors.horizontalCenter: parent.horizontalCenter

            onValueChanged: {
                foodata1.value = value  // #1
            }
        }

        Text {
            text: foodata2.value  // #2
            font.pixelSize: 20
            anchors.horizontalCenter: parent.horizontalCenter
        }

        Slider {
            value: foodata2.value  // #2
            from: -100.0
            to:  100.0
            anchors.horizontalCenter: parent.horizontalCenter

            onValueChanged: {
                foodata2.value = value  // #2
            }
        }
    }
}
