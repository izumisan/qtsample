import QtQuick 2.11
import QtQuick.Controls 2.4
import QtQuick.Window 2.11

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("State Sample 2")

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

            Button {
                anchors {
                    right: parent.right
                    bottom: parent.bottom
                    rightMargin: 5
                    bottomMargin: 5
                }

                text: _stateGroup.state !== "" ? _stateGroup.state : "undefined"

                onClicked: {
                    switch ( _stateGroup.state ) {
                    case "state1":
                        _stateGroup.state = "state2"
                        break
                    case "state2":
                        _stateGroup.state = "state3"
                        break
                    case "state3":
                        _stateGroup.state = "state1"
                        break
                    case "":
                        _stateGroup.state = "state1"
                        break
                    default:
                        break
                    }
                }
            }
        }

        StateGroup {
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

        StateGroup {
            id: _stateGroup
            states: [
                State {
                    name: "state1"
                    PropertyChanges {
                        target: _rect
                        color: "purple"
                    }
                },
                State {
                    name: "state2"
                    PropertyChanges {
                        target: _rect
                        color: "olive"
                    }
                },
                State {
                    name: "state3"
                    PropertyChanges {
                        target: _rect
                        color: "teal"
                    }
                }
            ]
        }
    }
}
