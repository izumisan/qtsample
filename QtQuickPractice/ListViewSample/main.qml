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
            ListElement { name: "item 1" }
            ListElement { name: "item 2" }
            ListElement { name: "item 3" }
            ListElement { name: "item 4" }
            ListElement { name: "item 5" }
            ListElement { name: "item 6" }
            ListElement { name: "item 7" }
            ListElement { name: "item 8" }
            ListElement { name: "item 9" }
            ListElement { name: "item 10" }
            ListElement { name: "item 11" }
            ListElement { name: "item 12" }
        }

        delegate: Rectangle {
            width: listview.width
            height: label.contentHeight * 3
            radius: 15
            border.width: 1
            border.color: "lightgray"
            Label {
                id: label
                text: model.name
                font.pixelSize: 14
                anchors.centerIn: parent
            }
        }
    }
}
