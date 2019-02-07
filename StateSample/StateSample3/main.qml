import QtQuick 2.11
import QtQuick.Controls 2.4
import QtQuick.Window 2.11

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("State Sample 3")

    property double value: 1

    Label {
        id: _label
        anchors.centerIn: parent
        text: value
        font.pixelSize: 72
    }

    Button {
        anchors {
            top: _label.bottom
            topMargin: 50
            horizontalCenter: parent.horizontalCenter
        }
        width: 100
        text: _stateGroup.state !== "" ? _stateGroup.state : "undefined"

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

    StateGroup {
        id: _stateGroup
        states: [
            State {
                name: "state1"
                // StateChangeScript
                // 状態がstate1に遷移した時、指定したスクリプト（enterState1）を実行する
                StateChangeScript {
                    script: enterState1()
                }
            },
            State {
                name: "state2"
                StateChangeScript {
                    script: enterState2()
                }
            },
            State {
                name: "state3"
                StateChangeScript {
                    script: enterState3()
                }
            }
        ]
    }

    function enterState1() {
        value += 1
    }

    function enterState2() {
        value += 2
    }

    function enterState3() {
        value += 3
    }
}
