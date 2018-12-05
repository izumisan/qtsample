import QtQuick 2.11
import QtQuick.Window 2.11
import QtQuick.Layouts 1.11
import QtQuick.Controls 2.4

import viewmodels 1.0

Window {
    visible: true
    width: 300
    height: 300
    title: qsTr("Observable Property 3")

    MainViewModel { id: vm }

    ColumnLayout {
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter

        SpinBox {
            value: vm.ivalue.value
            onValueChanged: vm.ivalue.value = value
        }
        Label {
            text: vm.ivalue2.value
            Layout.alignment: Qt.AlignHCenter
        }
        Button {
            text: "subscribe"
            onClicked: vm.onSubscribe()
        }
        Button {
            text: "unsubscribe"
            onClicked: vm.onUnsubscribe()
        }

        Button {
            text: "qdebug"
            onClicked: vm.printdebug()
        }
    }
}
