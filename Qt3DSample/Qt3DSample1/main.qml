import QtQuick 2.11
import QtQuick.Window 2.11
import QtQuick.Scene3D 2.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Teapot")

    //@@@ Qt3Dを使ってみよう
    //@@@ https://qiita.com/shin1_okada/items/dcf1fd1124a83fefd797

    //@@@ サンプル1（teapot）の写経

    Scene3D {
        anchors.fill: parent
        focus: true
        aspects: ["input", "logic"]
        Stage {}
    }
}
