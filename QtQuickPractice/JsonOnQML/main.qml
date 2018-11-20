import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.2

import Foo 1.0

Window {
    visible: true
    width: 300
    height: 200
    title: qsTr("Json on QML")

    Foo { id: _foo }

    property var foojsonobj: JSON.parse( _foo.json )

    ColumnLayout {
        anchors.centerIn: parent

        Label { text: _foo.json }
        Label { text: foojsonobj.name }
        Label { text: JSON.parse( _foo.json ).value }
        Label { text: JSON.parse( _foo.json ).str }
    }

    Component.onCompleted: {
        var jsonstring = '{"name": "bar", "value": 1.234}'
        var jsonobject = JSON.parse(jsonstring)

        console.log( jsonobject.name )
        console.log( jsonobject.value )
    }
}
