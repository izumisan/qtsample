import QtQuick 2.11
import QtQuick.Window 2.11

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Drag&Drop")

    Rectangle {
        width: parent.width
        height: parent.height / 2
        color: "gray"

        Text {
            anchors.centerIn: parent
            text: "Drop Area"
            color: "white"
        }

        // ドロップエリア
        DropArea {
            id: _dropArea
            anchors.fill: parent

            onEntered: {
                console.log( "onEntered" )
            }

            onDropped: {
                console.log( "onDropped" )
            }

            onExited: {
                console.log( "onExited" )
            }
        }
    }

    // ドラッグエリア（ドラッグ対象）
    Rectangle {
        x: 100
        y: parent.height * 0.75
        width: 50
        height: 50

        color: "blue"

        Drag.active: _dragArea.drag.active

        // ホットスポット（DropAreaとの当たり判定ポイント(1ピクセル)）
        // 中心座標をホットスポットに設定
        Drag.hotSpot.x: width / 2
        Drag.hotSpot.y: height / 2

        MouseArea {
            id: _dragArea
            anchors.fill: parent

            // ドラッグ対象を指定
            drag.target: parent
            onReleased: {
                console.log("onReleased")
                parent.Drag.drop()
            }
        }
    }
}
