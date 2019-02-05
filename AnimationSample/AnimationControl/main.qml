import QtQuick 2.11
import QtQuick.Controls 2.4
import QtQuick.Window 2.11

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("アニメーション制御")

    Rectangle {
        id: _rect
        anchors.centerIn: parent
        width: 200
        height: width
        color: "royalblue"

        Text {
            anchors.centerIn: parent
            text: _rect.rotation.toFixed(0)
            color: "white"
            font.pixelSize: 36
        }

        RotationAnimation {
            id: _animation
            target: _rect
            from: 0
            to: 360
            direction: RotationAnimation.Clockwise
            duration: 12000
            loops: Animation.Infinite
        }
    }

    Row {
        anchors {
            bottom: parent.bottom
            bottomMargin: 10
            horizontalCenter: parent.horizontalCenter
        }
        spacing: 2

        Button {
            text: "start"
            onClicked: _animation.start()
        }
        Button {
            text: "pause"
            onClicked: _animation.pause()
        }
        Button {
            text: "resume"
            onClicked: _animation.resume()
        }
        Button {
            text: "restart"
            onClicked: _animation.restart()
        }
        Button {
            text: "stop"
            onClicked: _animation.stop()
        }
        Button {
            text: "complete"
            onClicked: _animation.complete()
        }
    }
}
