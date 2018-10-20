import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.3

Window {
    visible: true
    width: 200
    height: 400
    title: qsTr("ListView Sample")

    ListView {
        id: listview
        anchors.fill: parent
        anchors.topMargin: 40
        ScrollBar.vertical: ScrollBar{}

        model: ListModel {
            ListElement { name: "ほわいと" }
            ListElement { name: "black" }
            ListElement { name: "cyan" }
            ListElement { name: "darkCyan" }
            ListElement { name: "red" }
            ListElement { name: "darkRed" }
            ListElement { name: "magenta" }
            ListElement { name: "darkMagenta" }
            ListElement { name: "green" }
            ListElement { name: "darkGreen" }
            ListElement { name: "yellow" }
            ListElement { name: "darkYellow" }
            ListElement { name: "blue" }
            ListElement { name: "darkBlue" }
            ListElement { name: "gray" }
            ListElement { name: "darkGray" }
            ListElement { name: "lightGray" }
        }

        delegate: Rectangle {
            width: listview.width
            height: label.contentHeight * 3
            radius: 15
            border.width: 1
            border.color: "lightgray"
            Label {
                id: label
                text: model.index + " : " + model.name
                color: model.name
                font.pixelSize: 14
                anchors.centerIn: parent
            }
        }
    }
}
