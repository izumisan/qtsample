import QtQuick 2.11
import QtQuick.Window 2.11
import QtQuick.Layouts 1.11
import QtQuick.Controls 2.4

import viewmodels 1.0

Window {
    visible: true
    width: 300
    height: 500
    title: qsTr("Observable Property 2")

    MainViewModel { id: vm }

    ColumnLayout {
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter

        TextField {
            text: vm.str.value
            onTextChanged: vm.str.value = text
        }
        SpinBox {
            value: vm.ivalue.value
            onValueChanged: vm.ivalue.value = value
        }
        TextField {
            text: vm.dvalue.value
            onTextChanged: vm.dvalue.value = text
        }
        TextField {
            text: vm.foo1name.value
            onTextChanged: vm.foo1name.value = text
        }
        SpinBox {
            value: vm.foo1value.value
            onValueChanged: vm.foo1value.value = value
        }
        TextField {
            text: vm.foo2name.value
            onTextChanged: vm.foo2name.value = text
        }
        SpinBox {
            value: vm.foo2value.value
            onValueChanged: vm.foo2value.value = value
        }

        Button {
            text: "qdebug"
            onClicked: vm.printdebug()
        }
    }
}
