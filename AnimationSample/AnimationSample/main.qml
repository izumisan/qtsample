import QtQuick 2.11
import QtQuick.Window 2.11
import QtQuick.Controls 2.4

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Animation Sample")

    Label {
        id: _label
        anchors.centerIn: parent
        antialiasing: true

        text: "Foo"
    }

    // アニメーションの設定
    NumberAnimation {
        target: _label
        property: "font.pointSize"
        from: 10
        to: 200
        duration: 10000  // [msec]
        running: true
        loops: Animation.Infinite  // ループ回数を指定（Infinite(-1)で無限ループ）
    }

    Label {
        anchors {
            bottom: parent.bottom
            bottomMargin: 10
            horizontalCenter: parent.horizontalCenter
        }
        text: "font.pixelSize: " + _label.font.pointSize.toFixed(1)
    }
}
