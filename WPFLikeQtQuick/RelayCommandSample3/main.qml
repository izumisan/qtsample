import QtQuick 2.9
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.3
import QtQuick.Window 2.2

import viewmodel 1.0

Window {
    visible: true
    width: 300
    height: 300
    title: qsTr("RelayCommand Sample 3")

    MainViewModel { id: vm }

    function vmfunc() {
        console.log( "start..." )
        vm.doSomething()
        console.log( "end" )
    }

    ColumnLayout {
        anchors.centerIn: parent

        Button {
            text: "slots"
            Layout.fillWidth: true
            Layout.alignment: Qt.AlignHCenter

            onClicked: vmfunc()
        }

        Button {
            text: "action"
            Layout.fillWidth: true
            Layout.alignment: Qt.AlignHCenter

            action: Action {
                onTriggered: vmfunc()
            }
        }

        Button {
            text: "command"
            Layout.fillWidth: true
            Layout.alignment: Qt.AlignHCenter

            action: Command { command: vm.relayCommand }
        }

        Button {
            text: "async command"
            Layout.fillWidth: true
            Layout.alignment: Qt.AlignHCenter

            action: Command { command: vm.asyncCommand }
        }
    }
}
