import QtQuick 2.15
import QtQuick.Templates 2.15 as T

T.Button {
    id: control

    font: Style.baseTextFont

    property color textColor: "black"
    property color backgroundColor: "gray"
    property color backgroundBorderColor: Style.borderColor
    property color hoverColor: Qt.lighter(backgroundColor, 1.1)
    property color borderHoverColor: Style.borderColor
    property color downColor: Qt.lighter(backgroundColor, 1.2)
    property color borderDownColor: Style.borderColor

    contentItem: Text {
        anchors.fill: parent
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        text: control.text
        font: control.font
        color: textColor
    }

    background: Rectangle {
        color: control.hovered? (control.down  ?
                                          control.downColor :
                                          control.hoverColor) :
                                     control.backgroundColor
        border.color: control.hovered? (control.down  ?
                                            control.borderDownColor :
                                            control.borderHoverColor) :
                                       control.backgroundBorderColor
        border.width: Style.borderWidth
    }
}
