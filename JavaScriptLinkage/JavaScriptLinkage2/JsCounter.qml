import QtQuick 2.4
import "counter.js" as Counter

JsCounterForm {
    button.onClicked: label.text = Counter.next()
}
