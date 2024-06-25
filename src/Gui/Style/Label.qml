import QtQuick 2.15
import QtQuick.Templates 2.15 as T

T.Label {
    id: control

    leftPadding: 10
    verticalAlignment: Qt.AlignVCenter
    font: Style.baseTextFont

    background: Rectangle {
        color: "lightgray"
        border.width: Style.borderWidth
        border.color: Style.borderColor
    }
}
