import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.3

import FooLibrary 1.0

Window {
    visible: true
    width: 300
    height: 200
    title: qsTr("Property Binding 4")

    Foo { id: foo }

    Column {

        anchors.centerIn: parent

        Text {
            text: foo.bar.value  // C++プロパティ値の取得
            font.pixelSize: 20
            anchors.horizontalCenter: parent.horizontalCenter
        }

        Slider {
            value: foo.bar.value  // C++プロパティ値の取得
            from: -100.0
            to:  100.0
            anchors.horizontalCenter: parent.horizontalCenter

            onValueChanged: {
                foo.bar.value = value  // C++プロパティ値の設定
            }
        }
    }
}
