import QtQuick 2.0
import QtQuick.Controls 2.4

Dialog {
    width: 250
    modal: true  // モーダル

    title: "タイトル"
    contentItem: Text { text: "コンテンツ" }
    standardButtons: ( DialogButtonBox.Ok | DialogButtonBox.Cancel )

    onAccepted: console.log("onAccepted")
    onRejected: console.log("onRejected")

    Component.onCompleted: console.log("Component.onCompleted")
}
