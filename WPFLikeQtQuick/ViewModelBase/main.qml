import QtQuick 2.11
import QtQuick.Window 2.11
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.3
import viewmodels 1.0

Window {
    visible: true
    width: 200
    height: 200
    title: qsTr("VewModelBase")

    MainViewModel { id: vm }

    ColumnLayout {
        anchors.centerIn: parent

        Button {
            text: vm.ivalue.value
            onClicked: {
                vm.onClicked1()
            }
        }

        Button {
            text: vm.dvalue.value.toFixed(3)
            onClicked: {
                vm.onClicked2()
            }
        }
    }
}
