import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.4

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Dialogサンプル")

    Button {
        anchors.centerIn: parent
        text: "Open"

        onClicked: _dialog.open()
    }

    Item {
        anchors.centerIn: parent
        width: _dialog.width
        height: _dialog.height

        Dialog {
            id: _dialog
            width: 250
            modal: true  // モーダル

            title: "タイトル"
            contentItem: Text { text: "コンテンツ" }
            standardButtons: DialogButtonBox.Ok | DialogButtonBox.Cancel

            onAccepted: console.log("onAccepted")
            onRejected: console.log("onRejected")

            Component.onCompleted: console.log("Component.onCompleted")
        }
    }
}
