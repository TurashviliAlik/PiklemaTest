pragma Singleton
import QtQuick 2.15

QtObject {
    readonly property real borderWidth: 2
    readonly property real spacing: -borderWidth
    readonly property color borderColor: "black"
    readonly property font baseTextFont: Qt.font({pointSize: 12})
}
