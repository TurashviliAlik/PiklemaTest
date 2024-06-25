import QtQuick 2.15
import QtQuick.Window 2.15

import PiklemaTest 1.0

Window {
    id: root

    title: "PiklemaTest"

    visible: true
    width: 600

    minimumHeight: contentItem.childrenRect.height
    maximumHeight: minimumHeight

    MainPage {
        width: parent.width
    }

    onClosing: Qt.quit()
}
