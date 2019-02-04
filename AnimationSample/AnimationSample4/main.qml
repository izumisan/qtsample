import QtQuick 2.11
import QtQuick.Controls 2.4
import QtQuick.Window 2.11

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("あにめーしょん4")

    Rectangle {
        id: _rect
        anchors.fill: parent
        width: 150
        height: 150
        color: "gray"

        StateGroup {
            id: _stateGroup
            states: [
                State {
                    name: "state1"
                    PropertyChanges {
                        target: _rect
                        color: "red"
                    }
                },
                State {
                    name: "state2"
                    PropertyChanges {
                        target: _rect
                        color: "green"
                    }
                },
                State {
                    name: "state3"
                    PropertyChanges {
                        target: _rect
                        color: "blue"
                    }
                }
            ]

            transitions: [
                // state1からstate2に遷移する時、アニメーションを実行する
                Transition {
                    id: _colorAnimation
                    from: "state1"
                    to: "state2"
                    ColorAnimation {
                        target: _rect
                        duration: 2000
                    }
                }
            ]
        }

        Button {
            anchors {
                bottom: parent.bottom
                bottomMargin: 10
                right: parent.right
                rightMargin: 10
            }
            text: "NEXT"
            // アニメーション実行中は非活性
            enabled: !_colorAnimation.running

            onClicked: {
                switch ( _stateGroup.state ) {
                case "state1":
                    _stateGroup.state = "state2"
                    break;
                case "state2":
                    _stateGroup.state = "state3"
                    break;
                case "state3":
                    _stateGroup.state = "state1"
                    break;
                default:
                    _stateGroup.state = "state1"
                    break;
                }
            }
        }
    }

    Text {
        anchors.centerIn: parent
        text: _rect.color
        color: "white"
        font.pointSize: 16
    }
}
