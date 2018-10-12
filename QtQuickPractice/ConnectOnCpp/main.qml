import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.3

Window {
    visible: true
    width: 300
    height: 200
    title: qsTr("Connect on C++")

    // QMLシグナル
    signal buttonClicked();

    // QMLスロット
    function setLabelText( text ) {
        label.text = text
    }

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
            text: "next"
            onClicked: buttonClicked()  // QMLシグナルの発行
        }
    }
}
