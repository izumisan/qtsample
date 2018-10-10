import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.3

Window {
    visible: true
    width: 400
    height: 300
    title: qsTr("Hello World")

    Column {
        anchors.centerIn: parent
        spacing: 10

        Text {
            text: qsTr( "Hello World" )
            anchors.horizontalCenter: parent.horizontalCenter
            font.italic: true
            font.pointSize: 20
        }

        Button {
            text: "console.log"
            anchors.horizontalCenter: parent.horizontalCenter
            onClicked: {
                console.log( "button clicked" )
            }
        }

        Button {
            text: "quit"
            anchors.horizontalCenter: parent.horizontalCenter
            onClicked: {
                console.debug( "quit button colicked. byeノシ" )
                Qt.quit()
            }
        }
    }
}
