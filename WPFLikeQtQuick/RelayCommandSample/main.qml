import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3

import viewmodel 1.0

Window {
    id: window
    visible: true
    width: 200
    height: 200
    title: qsTr("RelayCommand Sample")

    MainViewModel { id: vm }

    ColumnLayout {
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter

        SpinBox {
            onValueChanged: vm.value = value
        }

        Button {
            Layout.fillWidth: true
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter

            text: qsTr("なべあつボタン")

            enabled: vm.fooCommand.canExecute

            onClicked: vm.fooCommand.execute()
        }
    }
}
