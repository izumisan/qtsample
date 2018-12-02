import QtQuick 2.11
import QtQuick.Window 2.11
import QtQuick.Layouts 1.11
import QtQuick.Controls 2.4

import viewmodels 1.0

Window {
    visible: true
    width: 300
    height: 200
    title: qsTr("Observable Property")

    MainViewModel { id: vm }

    ColumnLayout {
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter

        Label { text: vm.foo.value }
        Label { text: vm.foo2.value }
    }
}
