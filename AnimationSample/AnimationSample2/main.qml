import QtQuick 2.11
import QtQuick.Window 2.11

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("あにめーしょん2")

    Rectangle {
        id: _rect
        x: 100; y: 100
        width: 40
        height: width
        radius: width / 2
        color: "royalblue"

        // Behaviorエレメント
        // プロパティが変化する時、指定したアニメーションを実行する
        Behavior on x {
            NumberAnimation {
                duration: 2000
                easing.type: Easing.OutBounce  // イージングの設定（バウンド）
            }
        }

        Behavior on y {
            NumberAnimation {
                duration: 2000
                easing.type: Easing.OutBounce
            }
        }
    }

    MouseArea {
        anchors.fill: parent

        // _rectをマウスクリックの位置に設定する
        onClicked: {
            _rect.x = mouse.x - _rect.width / 2
            _rect.y = mouse.y - _rect.height / 2
        }
    }

    Row {
        anchors {
            bottom: parent.bottom
            bottomMargin: 10
            horizontalCenter: parent.horizontalCenter
        }
        Text { text: "x: " }
        Text { text: _rect.x.toFixed(1) }
        Text { text: ", y: " }
        Text { text: _rect.y.toFixed(1) }
    }
}
