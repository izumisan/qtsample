import QtQuick 2.11
import QtQuick.Window 2.11
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.3
import viewmodels 1.0

Window {
    visible: true
    width: 300
    height: 400
    title: qsTr("Observable Collection 2")

    MainViewModel { id: vm }

    ColumnLayout {
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        anchors.bottom: parent.bottom

        ListView {
            height: contentHeight
            width: contentWidth

            model: vm.foos

            delegate: SpinBox {
                value: model.value
                onValueChanged: model.value = value
            }
        }
        ListView {
            height: contentHeight
            width: contentWidth

            model: vm.foos

            delegate: Label {
                text: model.name + " : " + model.value
            }
        }
        ListView {
            height: contentHeight
            width: contentWidth

            model: vm.foos2

            delegate: Label {
                text: model.name + " : " + model.value
            }
        }

        Button {
            text: "qdebug"
            onClicked: vm.printdebug()
        }
    }
}
