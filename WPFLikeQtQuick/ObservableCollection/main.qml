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
//        anchors.horizontalCenter: parent.horizontalCenter
//        anchors.verticalCenter: parent.verticalCenter
        anchors.fill: parent

        ListView {
            anchors.fill: parent
//            Layout.alignment: Qt.AlignHCenter
            model: vm.ivalues
//            model: ListModel {
//                ListElement { foo: "1" }
//                ListElement { foo: "2" }
//                ListElement { foo: "3" }
//                ListElement { foo: "3" }
//                ListElement { foo: "3" }
//                ListElement { foo: "3" }
//            }

            delegate: ItemDelegate {
                text: index + ":" + foo
            }
        }

        Button {
            text: "qdebug"
            onClicked: vm.printdebug()
        }
    }
}
