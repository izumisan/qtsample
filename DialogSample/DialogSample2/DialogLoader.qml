import QtQuick 2.0

Item {
    id: _dialogRoot

    property string qmlfile: ""

    function open() {
        var component = Qt.createComponent( qmlfile )
        if( component.status === Component.Ready ) {
            var dialog = component.createObject( _dialogRoot )
            dialog.open()

            _dialogRoot.width = dialog.width
            _dialogRoot.height = dialog.height
        } else {
            console.error( component.errorString() )
        }
    }
}
