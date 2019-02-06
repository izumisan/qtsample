import QtQuick 2.11
import QtQuick.Window 2.11

Window {
    id: _root
    visible: true
    width: 640
    height: 480
    title: qsTr("あにめーしょん 5")

    property point p0: Qt.point( 100, 100 )
    property point p1: Qt.point( width - 100, 100 )
    property point p2: Qt.point( width - 100, height - 100 )
    property point p3: Qt.point( 100, height - 100 )

    Rectangle {
        id: _rect
        x: p0.x - width * 0.5
        y: p0.y - height * 0.5
        width: 80
        height: width
        color: "royalblue"

        Text {
            id: _text
            anchors.centerIn: parent
            color: "white"
            font.pixelSize: 16
        }
    }

    // SequentialAnimation
    // アニメーションを連続実行する
    SequentialAnimation {
        running: true
        loops: Animation.Infinite

        // ScriptAction
        // スクリプトを実行する
        ScriptAction { script: setText( "0 >>> 1" ) }

        // 右移動
        NumberAnimation {
            target: _rect
            properties: "x"
            to: p1.x - _rect.width * 0.5
            duration: 2000
        }

        ScriptAction { script: setText( "1 >>> 2" ) }

        // 下移動
        NumberAnimation {
            target: _rect
            properties: "y"
            to: p2.y - _rect.height * 0.5
            duration: 2000
        }

        ScriptAction { script: setText( "2 >>> 3" ) }

        // ParallelAnimation
        // 複数のアニメーションを同時実行する
        ParallelAnimation {
            // 左移動
            NumberAnimation {
                target: _rect
                properties: "x"
                to: p3.x - _rect.width * 0.5
                duration: 2000
            }
            RotationAnimation {
                target: _rect
                from: 0
                to: 360
                direction: RotationAnimation.Clockwise
                duration: 1000
                loops: 2
            }
        }

        ScriptAction { script: setText( "3 >>> 0" ) }

        // 上移動
        NumberAnimation {
            target: _rect
            properties: "y"
            to: p0.y - _rect.height * 0.5
            duration: 2000
        }
    }

    function setText( text ) {
        _text.text = text
    }
}
