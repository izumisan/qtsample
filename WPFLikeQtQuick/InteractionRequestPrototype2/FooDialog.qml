import QtQuick 2.0
import QtQuick.Controls 2.4

Dialog {
    width: 250
    modal: true  // モーダル

    title: "Fooダイアログ"
    contentItem: Text { text: "Fooコンテンツ" }
    standardButtons: ( DialogButtonBox.Ok | DialogButtonBox.Cancel )

    onAccepted: console.log("Foo Accepted")
    onRejected: console.log("Foo Rejected")

    Component.onCompleted: console.log("FooDialog loaded")
}
