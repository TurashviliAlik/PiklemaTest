!include("$$BASEDIR/common.pri") {
    error("Не удалось подключить common.pri!")
}

TEMPLATE = lib
TARGET = piklematestmodelplugin
QT += qml quick
CONFIG += qt plugin qmltypes

QML_IMPORT_NAME = PiklemaTest.Model
QML_IMPORT_MAJOR_VERSION = 1

TARGET = $$qtLibraryTarget($$TARGET)
DESTDIR = $$INSTALL_DIR/qml/PiklemaTest/Model
QMLTYPES_FILENAME = $$DESTDIR/plugins.qmltypes

HEADERS += \
    Model.h \
    ModelPlugin.h

SOURCES += \
    Model.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$INSTALL_DIR/libs/release/ -lTools
else:win32:CONFIG(debug, debug|release): LIBS += -L$$INSTALL_DIR/libs/debug/ -lTools
else:unix: LIBS += -L$$INSTALL_DIR/libs/ -lTools

INCLUDEPATH += $$BASEDIR/src/Tools
DEPENDPATH += $$BASEDIR/src/Tools

!equals(_PRO_FILE_PWD_, $$OUT_PWD) {
    copy_qmldir.files = $$PWD/qmldir
    copy_qmldir.path = $$DESTDIR
    COPIES += copy_qmldir
}

