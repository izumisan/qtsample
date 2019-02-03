import QtQuick 2.11
import QtQuick.Window 2.11

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("あにめーしょん3")

    MouseArea {
        id: _mouseArea
        anchors.fill: parent

        Rectangle {
            id: _rect
            anchors.centerIn: parent
            width: 150
            height: 150
            color: "red"

            states: [
                State {
                    when: _mouseArea.pressed
                    PropertyChanges {
                        target: _rect
                        color: "blue"
                    }
                }
            ]

            transitions: [
                // Transitionエレメント
                // 状態が遷移した時、指定したアニメーションを実行する
                Transition {
                    ColorAnimation {
                        target: _rect
                        duration: 2000
                    }
                }
            ]

            Text {
                anchors.centerIn: parent
                text: _rect.color
                color: "white"
                font.pointSize: 16
            }
        }
    }
}
