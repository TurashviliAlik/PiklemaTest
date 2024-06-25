import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import QtQuick.Dialogs 1.3

import PiklemaTest 1.0
import PiklemaTest.ModelInstance 1.0
import PiklemaTest.Style 1.0

Item {
    id: root

    width: 600
    implicitHeight: childrenRect.height

    GridLayout {
        width: parent.width
        columns: 2
        rowSpacing: Style.spacing
        columnSpacing: Style.spacing

        Label {
            Layout.preferredWidth: 150
            Layout.preferredHeight: 30
            text: "host"
        }

        TextField {
            Layout.fillWidth: true
            Layout.preferredHeight: 30
            text: Model.host
            Component.onCompleted: Model.host = Qt.binding(()=> text)
        }

        Label {
            Layout.preferredWidth: 150
            Layout.preferredHeight: 30
            text: "port"
        }

        TextField {
            Layout.fillWidth: true
            Layout.preferredHeight: 30
            validator: IntValidator {
                bottom: 0
                top: Math.pow(2, 16) - 1
            }
            text: Model.port
            Component.onCompleted: Model.port = Qt.binding(()=> text)
        }

        Label {
            Layout.preferredWidth: 150
            Layout.preferredHeight: 30
            text: "username"
        }

        TextField {
            Layout.fillWidth: true
            Layout.preferredHeight: 30
            text: Model.username
            Component.onCompleted: Model.username = Qt.binding(()=> text)
        }

        Label {
            Layout.preferredWidth: 150
            Layout.preferredHeight: 30
            text: "password"
        }

        TextField {
            Layout.fillWidth: true
            Layout.preferredHeight: 30
            text: Model.password
            Component.onCompleted: Model.password = Qt.binding(()=> text)
        }

        Label {
            Layout.preferredWidth: 150
            Layout.preferredHeight: 30
            text: "topic"
        }

        TextField {
            Layout.fillWidth: true
            Layout.preferredHeight: 30
            text: Model.topic
            Component.onCompleted: Model.topic = Qt.binding(()=> text)
        }

        Label {
            Layout.preferredWidth: 150
            Layout.preferredHeight: 30
            text: "filepath"
        }

        RowLayout {
            Layout.fillWidth: true
            Layout.preferredHeight: 30
            spacing: Style.spacing
            TextField {
                id: filepathInput
                Layout.fillWidth: true
                Layout.fillHeight: true
                text: Model.filepath
                Component.onCompleted: Model.filepath = Qt.binding(()=> text)
            }
            Button {
                Layout.columnSpan: 2
                Layout.preferredWidth: 100
                Layout.fillHeight: true
                text: "Выбрать"
                onClicked: fileChooser.open()

                FileDialog {
                    id: fileChooser
                    onAccepted: filepathInput.text = fileUrl
                }
            }
        }

        Button {
            Layout.columnSpan: 2
            Layout.fillWidth: true
            Layout.preferredHeight: 30
            text: "RUN"
            onClicked: Controller.publish()
        }

        Label {
            Layout.columnSpan: 2
            Layout.fillWidth: true
            Layout.preferredHeight: 30
            text: "Отпнравлено сообщений: " + Model.messagesSentCount
        }

        Label {
            Layout.columnSpan: 2
            Layout.fillWidth: true
            Layout.preferredHeight: 30
            text: "Состояние: " + Model.status
        }

        Label {
            Layout.columnSpan: 2
            Layout.fillWidth: true
            Layout.preferredHeight: 30
            text: "Ошибки: " + Model.errorMessage
        }
    }
}
