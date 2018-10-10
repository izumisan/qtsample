import QtQuick 2.6
import QtQuick.Window 2.2

Window {
    visible: true
    width: 300
    height: 200
    title: qsTr("QML access C++ method")

    Text {
        text: foodata.message()  // C++側のメソッド呼び出し
        anchors.centerIn: parent
    }
}
