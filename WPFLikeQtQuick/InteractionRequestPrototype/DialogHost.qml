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
            console.log( "onRaised" )
            dialog.result = 0
            dialog.open()
        }
    }

    Connections {
        target: dialog
        onResultChanged: {
            console.log("onResultChanged:" + dialog.result)
            interactionRequest.context.resultCode = dialog.result
        }
        onAccepted: {
            console.log("onAccepted")
            interactionRequest.context.accepted()
        }
        onRejected: {
            console.log( "onRejected" )
            interactionRequest.context.rejected()
        }
        onClosed: {
            console.log( "onClosed" )
        }
    }
}
