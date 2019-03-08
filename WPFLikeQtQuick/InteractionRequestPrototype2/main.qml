import QtQuick 2.11
import QtQuick.Window 2.11
import QtQuick.Controls 2.4
import viewmodels 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("InteractionRequest prototype")

    MainWindowViewModel { id: _viewmodel }

//    DialogHost {
//        anchors.centerIn: parent

//        interactionRequest: _viewmodel.interactionRequest
//        dialog: Dialog {
//            width: 200
//            title: _viewmodel.interactionRequest.context.title
//            contentItem: Text { text: _viewmodel.interactionRequest.context.content }
//            standardButtons: Dialog.Ok | Dialog.Cancel
//        }
//    }

    DialogLoader {
        id: _loader
        anchors.centerIn: parent

        interactionRequest: _viewmodel.interactionRequest
        source: "qrc:FooDialog.qml"

        property var context: _viewmodel.interactionRequest.context
        title: context.title
//        contentItem: Text { text: context.content }
    }

    Button {
        anchors.centerIn: parent
        text: "open"
        onClicked: _viewmodel.open()
    }
}
