import QtQuick 2.15
import QtQuick.Templates 2.15 as T

T.TextField {
    id: control

    implicitHeight: 40
    implicitWidth: 300

    leftPadding: 10
    rightPadding: 10
    verticalAlignment: TextInput.AlignVCenter
    font: Style.baseTextFont

    background: Rectangle {
        color: "#F4F4F4"
        border.width: Style.borderWidth
        border.color: Style.borderColor
    }
}
