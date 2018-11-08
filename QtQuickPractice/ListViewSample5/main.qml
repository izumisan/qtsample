import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.3

import FooListModel 1.0

Window {
    visible: true
    width: 200
    height: 480
    title: qsTr("ListView Sample 5")

    FooListModel { id: fooListModel }

    ListView {
        id: listview
        anchors.fill: parent
        Layout.fillWidth: true
        ScrollBar.vertical: ScrollBar{}

        model: fooListModel

        delegate: Rectangle {
            width: listview.width
            height: label.contentHeight * 3
            radius: 15
            border.width: 1
            border.color: "lightgray"
            Label {
                id: label
                text: "#" + index + " : " + name + " (" + count + ")"
                color: colorRole
                font.pixelSize: 14
                anchors.centerIn: parent
            }
        }

        MouseArea {
            anchors.fill: parent
            acceptedButtons: Qt.LeftButton
            onClicked: {
                fooListModel.pushBack()
            }
        }

        MouseArea {
            anchors.fill: parent
            acceptedButtons: Qt.RightButton
            onClicked: {
                fooListModel.removeFirst()
            }
        }
    }
}
