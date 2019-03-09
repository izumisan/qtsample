import QtQuick 2.0
import QtQuick.Controls 2.4

Item {
    id: _loader

    property var interactionRequest: null
    property string source: ""
    property var dialog: null
    property string title: ""
    property var contentItem: null

    function open() {
        var component = Qt.createComponent( source )
        if( component.status === Component.Ready ) {
            dialog = component.createObject( _loader )
            dialog.title = title
            dialog.contentItem = contentItem
            dialog.open()
        } else {
            console.error( component.errorString() )
        }
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
            dialog.destroy()
        }
    }
}
