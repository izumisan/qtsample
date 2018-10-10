import QtQuick 2.9
import QtQuick.Window 2.2

Window {
    visible: true
    width: 300
    height: 200
    title: qsTr("C++ access QML object")

    Text {
        id: textId
        objectName: "textObject"  // C++側からアクセスする際のQMLオブジェクト名
        text: qsTr( "Hello World" )
        anchors.centerIn: parent
    }
}
