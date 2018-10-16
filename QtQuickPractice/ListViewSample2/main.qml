import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.3

Window {
    visible: true
    width: 200
    height: 400
    title: qsTr("ListView Sample 2")

    ListView {
        id: listview
        anchors.fill: parent
        anchors.topMargin: 40
        ScrollBar.vertical: ScrollBar{}

        // C++モデルデータ（リスト）
        model: foolist

        delegate: Rectangle {
            width: listview.width
            height: label.contentHeight * 3
            radius: 15
            border.width: 1
            border.color: "lightgray"
            Label {
                id: label
                text: model.index + " : " + model.name
                color: model.color
                font.pixelSize: 14
                anchors.centerIn: parent
            }
        }
    }
}
