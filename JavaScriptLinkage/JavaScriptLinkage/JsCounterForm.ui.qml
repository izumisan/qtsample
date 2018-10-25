import QtQuick 2.4
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.3

Item {
    property alias label: label
    property alias button: button

    ColumnLayout {

        Label {
            id: label
            text: "label"
            font.pixelSize: 16
            Layout.alignment: "AlignHCenter"
        }
        Button {
            id: button
            text: "button"
            font.pixelSize: 12
            Layout.alignment: "AlignHCenter"
        }
    }
}
