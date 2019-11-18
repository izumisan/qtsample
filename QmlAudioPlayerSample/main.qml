import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.0
import QtMultimedia 5.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("QML Audio Player sample")

    Audio { id: _audio }

    Row {
        anchors.centerIn: parent
        spacing: 2
        Button {
            text: "よ、よろしくお願いします"
            onClicked: {
                // リソースファイルの再生
                _audio.source = "qrc:///voice/voice1.mp3"
                _audio.play()
            }
        }
        Button {
            text: "おめでとうございます"
            onClicked: {
                // ローカルファイルの再生
                _audio.source = "file:///" + applicationDirPath + "/../voice/voice2.mp3"
                _audio.play()
            }
        }

    }
}
