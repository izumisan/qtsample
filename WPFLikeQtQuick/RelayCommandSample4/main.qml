import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3

import viewmodel 1.0

Window {
    id: window
    visible: true
    width: 200
    height: 300
    title: qsTr("RelayCommand Sample 4")

    MainViewModel { id: vm }

    ColumnLayout {
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter

        SpinBox {
            id: spinbox

            Binding {
                target: vm
                property: "value"
                value: spinbox.value
            }
        }

        Button {
            Layout.fillWidth: true
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter

            text: qsTr("なべあつボタン")
            action: Command { command: vm.fooCommand }
        }

        Button {
            Layout.fillWidth: true
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter

            text: "start"
            onClicked: vm.start()
        }
        Button {
            Layout.fillWidth: true
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter

            text: "stop"
            onClicked: vm.stop()
        }
    }
}
