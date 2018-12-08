import QtQuick 2.11
import QtQuick.Window 2.11
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.3
import viewmodels 1.0

Window {
    visible: true
    width: 300
    height: 300
    title: qsTr("Observable Collection")

    MainViewModel { id: vm }

    ColumnLayout {
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        anchors.bottom: parent.bottom

        ListView {
            height: contentHeight
            width: contentWidth

            model: vm.ivalues

            delegate: SpinBox {
                value: model.ivalue
                onValueChanged: model.ivalue = value
            }
        }

        Button {
            text: "qdebug"
            onClicked: vm.printdebug()
        }
    }
}
