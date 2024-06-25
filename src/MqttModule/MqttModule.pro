!include("$$BASEDIR/common.pri") {
    error("Не удалось подключить common.pri!")
}

!include("$$BASEDIR/src/Share/Share.pri") {
    error("Не удалось подключить Share.pri!")
}

QT -= gui
QT += mqtt

TEMPLATE = lib

DESTDIR = $$INSTALL_DIR/libs

HEADERS += \
    IMqttModule.h \
    MqttModule.h

SOURCES += \
    MqttModule.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$INSTALL_DIR/qml/PiklemaTest/Model/release/ -lpiklematestmodelplugin
else:win32:CONFIG(debug, debug|release): LIBS += -L$$INSTALL_DIR/qml/PiklemaTest/Model/debug/ -lpiklematestmodelplugin
else:unix: LIBS += -L$$INSTALL_DIR/qml/PiklemaTest/Model/ -lpiklematestmodelplugin

INCLUDEPATH += $$BASEDIR/src/Model
DEPENDPATH += $$BASEDIR/src/Model
