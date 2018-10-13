import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.3

Window {
    visible: true
    width: 300
    height: 200
    title: qsTr("Connect on QML")

    Column {
        anchors.centerIn: parent
        spacing: 10

        Label {
            id: label
            text: "Ready"
            font.pixelSize: 20
            anchors.horizontalCenter: parent.horizontalCenter
        }

        Button {
            id: button
            text: "next"
        }
    }

    Connections {
        target: button

        onClicked: {
            fizzbuzz.next()
        }
    }

    Connections {
        target: fizzbuzz

        // シグナルハンドラ(on+シグナル名)
        onUpdated: {
            label.text = text
        }
    }
}
