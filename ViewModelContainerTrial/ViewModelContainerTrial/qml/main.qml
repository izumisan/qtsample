import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.0

import viewmodels 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    property var _foo: ViewModelProvider.viewModel( "foo" )
    property var _bar: ViewModelProvider.viewModel( "bar" )

    Column {
        anchors.centerIn: parent
        spacing: 8

        Label {
            text: "Foo"
            font.pointSize: 12
        }
        SpinBox {
            value: _foo.value
            onValueChanged: _foo.value = value
        }

        Label {
            text: "Bar"
            font.pointSize: 12
        }
        SpinBox {
            value: _bar.value
            enabled: false
        }
    }
}
