!include("$$BASEDIR/common.pri") {
    error("Не удалось подключить common.pri!")
}

TEMPLATE = lib
TARGET = piklematestplugin
QT += qml quick quickcontrols2
CONFIG += plugin qmltypes

QML_IMPORT_NAME = PiklemaTest
QML_IMPORT_MAJOR_VERSION = 1

TARGET = $$qtLibraryTarget($$TARGET)
DESTDIR = $$INSTALL_DIR/qml/$$QML_IMPORT_NAME
QMLTYPES_FILENAME = $$DESTDIR/plugins.qmltypes

QML_IMPORT_PATH += Qml

HEADERS += \
    PiklemaTestPlugin.h

RESOURCES += \
    $$PWD/Qml/qml.qrc \
    Style/style.qrc

!equals(_PRO_FILE_PWD_, $$OUT_PWD) {
    copy_qml.files = $$PWD/Qml/qmldir $$PWD/Qml/MainPage.qml
    copy_qml.path = $$DESTDIR

    copy_style.files = $$files($$PWD/Style/*.qml, true) $$PWD/Style/qmldir
    copy_style.path = $$DESTDIR/Style

    COPIES += copy_qml copy_style
}
