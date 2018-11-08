import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.3

import FooLibrary 1.0

Window {
    visible: true
    width: 300
    height: 200
    title: qsTr("SingletonTypeProvider")

    // Fooはシングルトンとして登録されているので、インスタンスは生成できない
    //Foo { id: foo }

    Column {

        anchors.centerIn: parent

        Text {
            text: Foo.bar.value  //@@@
            font.pixelSize: 20
            anchors.horizontalCenter: parent.horizontalCenter
        }

        Slider {
            value: Foo.bar.value  //@@@
            from: -100.0
            to:  100.0
            anchors.horizontalCenter: parent.horizontalCenter

            onValueChanged: {
                Foo.bar.value = value  //@@@
            }
        }
    }
}
