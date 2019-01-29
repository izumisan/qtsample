import QtQuick 2.11
import QtQuick.Window 2.11

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Drag & Drop 2")

    // ドロップエリア1
    DropArea {
        id: _dropArea1
        width: parent.width / 2 - 1
        height: parent.height / 2

        keys: ["item1"]

        Rectangle {
            anchors.fill: parent
            color: "gray"

            Text {
                anchors.centerIn: parent
                text: "Drop Area 1"
                color: "white"
            }
        }

        onEntered: {
            console.log( "onEntered: " + drag.source )
        }

        onDropped: {
            console.log( "onDropped: " + drag.source )
        }

        onExited: {
            console.log( "onExited: " + drag.source )
        }
    }

    // ドロップエリア2
    DropArea {
        id: _dropArea2
        anchors.right: parent.right
        width: parent.width / 2 - 1
        height: parent.height / 2

        keys: ["item2"]

        Rectangle {
            anchors.fill: parent
            color: "gray"

            Text {
                anchors.centerIn: parent
                text: "Drop Area 2"
                color: "white"
            }
        }

        onEntered: {
            console.log( "onEntered: " + drag.source )
        }

        onDropped: {
            console.log( "onDropped: " + drag.source )
        }

        onExited: {
            console.log( "onExited: " + drag.source )
        }
    }

    // ドラッグアイテム1
    Rectangle {
        x: 100
        y: parent.height * 0.75
        width: 50
        height: 50

        color: "red"

        Drag.keys: ["item1"]
        Drag.active: _dragArea1.drag.active
        Drag.hotSpot.x: width / 2
        Drag.hotSpot.y: height / 2

        Text {
            anchors.centerIn: parent
            text: "1"
            color: "white"
        }

        MouseArea {
            id: _dragArea1
            anchors.fill: parent

            drag.target: parent
            onReleased: {
                parent.Drag.drop()
            }
        }
    }

    // ドラッグアイテム2
    Rectangle {
        x: 300
        y: parent.height * 0.75
        width: 50
        height: 50

        color: "green"

        Drag.keys: ["item2"]
        Drag.active: _dragArea2.drag.active
        Drag.hotSpot.x: width / 2
        Drag.hotSpot.y: height / 2

        Text {
            anchors.centerIn: parent
            text: "2"
            color: "white"
        }

        MouseArea {
            id: _dragArea2
            anchors.fill: parent

            drag.target: parent
            onReleased: {
                parent.Drag.drop()
            }
        }
    }

    // ドラッグアイテム3
    Rectangle {
        x: 500
        y: parent.height * 0.75
        width: 50
        height: 50

        color: "blue"

        Drag.keys: ["item1", "item2"]
        Drag.active: _dragArea3.drag.active
        Drag.hotSpot.x: width / 2
        Drag.hotSpot.y: height / 2

        Text {
            anchors.centerIn: parent
            text: "1&2"
            color: "white"
        }

        MouseArea {
            id: _dragArea3
            anchors.fill: parent

            drag.target: parent
            onReleased: {
                parent.Drag.drop()
            }
        }
    }
}
