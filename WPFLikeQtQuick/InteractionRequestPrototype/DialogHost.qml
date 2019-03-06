import QtQuick 2.0
import QtQuick.Controls 2.4

Item {
    property var interactionRequest: null
    property var dialog: null

    width: dialog.width
    height: dialog.height

    Connections {
        target: interactionRequest
        onRaised: {
            interactionRequest.context.resultCode = 0
            dialog.open()
        }
    }

    Connections {
        target: dialog
        onResultChanged: interactionRequest.context.resultCode = dialog.result
        onAccepted: interactionRequest.accepted()
        onRejected: interactionRequest.rejected()
    }
}
