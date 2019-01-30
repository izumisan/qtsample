import QtQuick 2.11
import QtQuick.Window 2.11

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("State Sample")

    // statesプロパティはItemエレメントのプロパティ
    // WindowにstatesがないのでItemを配置
    Item {
        anchors.fill: parent

        Rectangle {
            id: _rect
            width: 100
            height: 100
            anchors.centerIn: parent
            color: "red"
        }

        MouseArea {
            id: _mouseArea
            width: 300
            height: 300
            anchors.centerIn: parent

            hoverEnabled: true

            Text {
                x: 5; y: 5
                text: "Mouse Area"
            }

            Rectangle {
                anchors.fill: parent
                border.color: "gray"
                color: "#00000000"  // 内部を透過
            }
        }

        // State配列
        // [0]: マウスエリアでマウスが押されている時、_rect.colorを"green"にする
        // [1]: マウスエリアにマウスカーソルがある時（ホバーしている時）、_rect.colorを"blue"にする
        //
        // Stateは先頭から順番に評価される
        // (マウスカーソルが押されている＆マウスエリアにカーソルがある場合、
        //  先に定義している"greenにする状態"が優先される
        states: [
            State {
                when: _mouseArea.pressed
                PropertyChanges {
                    target: _rect
                    color: "green"
                }
            },
            State {
                when: _mouseArea.containsMouse
                PropertyChanges {
                    target: _rect
                    color: "blue"
                }
            }
        ]
    }
}
