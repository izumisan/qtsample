import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3

Item {
    Rectangle {
        anchors.fill: parent
        color: "gray"

        Button {
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter

            text: qsTr("ぼたん")

            onClicked: {
                console.log( "clicked" )
            }
        }
    }
}