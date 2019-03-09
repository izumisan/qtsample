import QtQuick 2.0
import QtQuick.Controls 2.4

Item {
    property var interactionRequest: null
    property var dialog: null

    function open() {
        dialog.result = 0
        dialog.open()
    }

    width: dialog.width
    height: dialog.height

    Connections {
        target: interactionRequest
        onRaised: {
            console.log( "onRaised" )
            open()
        }
    }

    Connections {
        target: dialog
        property var context: interactionRequest.context
        onResultChanged: {
            console.log("onResultChanged:" + dialog.result)
            context.resultCode = dialog.result
        }
        onAccepted: {
            console.log("onAccepted")
            context.accepted()
        }
        onRejected: {
            console.log( "onRejected" )
            context.rejected()
        }
        onClosed: {
            console.log( "onClosed" )
        }
    }
}
