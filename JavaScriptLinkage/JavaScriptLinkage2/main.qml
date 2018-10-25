import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.3

Window {
    visible: true
    width: 400
    height: 400
    title: qsTr("JavaScript Linkage - stateless")

    ColumnLayout {
        anchors.centerIn: parent
        JsCounter {
            width: 100
            height: 100
            Layout.alignment: "AlignHCenter"
        }

        JsCounter {
            width: 100
            height: 100
            Layout.alignment: "AlignHCenter"
        }
    }
}
