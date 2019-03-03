import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.4

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Dialogサンプル 2")

    Button {
        anchors.centerIn: parent
        text: "Open"

        onClicked: _dialog.open()
    }

    DialogLoader {
        id: _dialog
        anchors.centerIn: parent
        qmlfile: "qrc:FooDialog.qml"
    }
}
