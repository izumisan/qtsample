import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.3

import FooLibrary 1.0

Window {
    visible: true
    width: 200
    height: 400
    title: qsTr("ListView Sample 3")

    FooManager {
        id: foomgr
        fooList: [
            Foo { name: "black"; color: name },
            Foo { name: "cyan"; color: name },
            Foo { name: "darkCyan"; color: name },
            Foo { name: "red"; color: name },
            Foo { name: "darkRed"; color: name },
            Foo { name: "magenta"; color: name },
            Foo { name: "darkMagenta"; color: name },
            Foo { name: "green"; color: name },
            Foo { name: "darkGreen"; color: name },
            Foo { name: "yellow"; color: name },
            Foo { name: "darkYellow"; color: name },
            Foo { name: "blue"; color: name },
            Foo { name: "darkBlue"; color: name },
            Foo { name: "gray"; color: name },
            Foo { name: "darkGray"; color: name },
            Foo { name: "lightGray"; color: name }
        ]
    }

    ListView {
        id: listview
        anchors.fill: parent
        anchors.topMargin: 40
        ScrollBar.vertical: ScrollBar{}

        model: foomgr.fooList

        delegate: Rectangle {
            width: listview.width
            height: label.contentHeight * 3
            radius: 15
            border.width: 1
            border.color: "lightgray"
            Label {
                id: label
                text: index + " : " + modelData.name
                color: modelData.color
                font.pixelSize: 14
                anchors.centerIn: parent
            }
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                console.debug( "onClicked" )
                foomgr.debugPrint()
            }
        }
    }
}
