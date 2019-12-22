import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.0

import viewmodels 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("ViewModelContainer Trial")

//    property FooViewModel _fooVM: ViewModelProvider2.getFromSharedPtr( "FooViewModel" )
//    property BarViewModel _barVM: ViewModelProvider2.getFromPtr( "BarViewModel" )
    property FooViewModel _fooVM: ViewModelProvider2.fooViewModel()
    property BarViewModel _barVM: ViewModelProvider2.barViewModel()

    Column {
        anchors.centerIn: parent
        spacing: 8

        Label {
            text: "FooViewModel"
            font.pointSize: 12
        }
        SpinBox {
            value: _fooVM.value
            onValueChanged: _fooVM.value = value
        }

        Label {
            text: "BarViewModel"
            font.pointSize: 12
        }
        SpinBox {
            value: _barVM.value
            enabled: false
        }
    }
}
