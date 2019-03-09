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

    DialogLoader {
        id: _loader
        anchors.centerIn: parent

        interactionRequest: _viewmodel.interactionRequest
        source: "qrc:FooDialog.qml"

        property var context: _viewmodel.interactionRequest.context
        property var dialogContent: Text { }

        onContextChanged: {
            title = context.title
            dialogContent.text = context.content
            contentItem = dialogContent
        }
    }

    Button {
        anchors.centerIn: parent
        text: "open"
        onClicked: _viewmodel.open()
    }
}
