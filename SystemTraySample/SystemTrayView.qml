import QtQuick 2.12
import Qt.labs.platform 1.1

SystemTrayIcon {
    id: _root
    visible: true
    iconSource: "qrc:/images/octcat.png"
    tooltip: qsTr("システムトレイさんぷる")

    //@@@ Memo:
    // 現状、一度表示したメニューはメニューアイテムをクリックしないと消去されない...
    // メニュー消去のためのコードが必要???

    menu: Menu {
        id: _menu
        MenuItem {
            text: qsTr("Information")
            onTriggered: _root.showMessage("title", "information message", SystemTrayIcon.Information, 500 )
        }
        MenuItem {
            text: qsTr("Warning")
            onTriggered: _root.showMessage("title", "warning message", SystemTrayIcon.Warning, 500 )
        }
        MenuItem {
            text: qsTr("Critical")
            onTriggered: _root.showMessage("title", "critical message", SystemTrayIcon.Critical, 500 )
        }
        MenuItem { separator: true }
        MenuItem {
            text: qsTr("Quit")
            onTriggered: Qt.quit()
        }
    }
    onActivated: {
        switch ( reason ) {
        case SystemTrayIcon.Trigger:
            console.log("left clicked.")
            break
        case SystemTrayIcon.MiddleClick:
            console.log("middle clicked.")
            break
        case SystemTrayIcon.Context:
            console.log("right clicked.")
            break;
        case SystemTrayIcon.DoubleClick:
            console.log("double clicked.")
            break
        default:
            console.log( reason )
            break
        }
    }
}
