import QtQuick 2.11
import QtQuick.Window 2.11

import QtQuickAppModule 1.0

Window {
    visible: true
    width: 400
    height: 300
    title: qsTr("QtQuickApp")

    MainView {
        anchors.fill: parent
    }
}
