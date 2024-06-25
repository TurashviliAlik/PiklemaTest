!include("$$BASEDIR/common.pri") {
    error("Не удалось подключить common.pri!")
}

!include("$$BASEDIR/src/Share/Share.pri") {
    error("Не удалось подключить Share.pri!")
}

QT += core qml

TEMPLATE = lib
DEFINES += CORE_LIBRARY

DESTDIR = $$INSTALL_DIR/libs

QML_IMPORT_PATH += \
    $$INSTALL_DIR/qml

HEADERS += \
    Application.h \
    Controller.h

SOURCES += \
    Application.cpp \
    Controller.cpp

RESOURCES += \
    main.qrc

win32:CONFIG(release, debug|release): LIBS += -L$$INSTALL_DIR/libs/release/ -lTools -lMqttModule
else:win32:CONFIG(debug, debug|release): LIBS += -L$$INSTALL_DIR/libs/debug/ -lTools -lMqttModule
else:unix: LIBS += -L$$INSTALL_DIR/libs/ -lTools -lMqttModule

win32:CONFIG(release, debug|release): LIBS += -L$$INSTALL_DIR/qml/PiklemaTest/release/ -lpiklematestplugin
else:win32:CONFIG(debug, debug|release): LIBS += -L$$INSTALL_DIR/qml/PiklemaTest/debug/ -lpiklematestplugin
else:unix: LIBS += -L$$INSTALL_DIR/qml/PiklemaTest/ -lpiklematestplugin

win32:CONFIG(release, debug|release): LIBS += -L$$INSTALL_DIR/qml/PiklemaTest/Model/release/ -lpiklematestmodelplugin
else:win32:CONFIG(debug, debug|release): LIBS += -L$$INSTALL_DIR/qml/PiklemaTest/Model/debug/ -lpiklematestmodelplugin
else:unix: LIBS += -L$$INSTALL_DIR/qml/PiklemaTest/Model/ -lpiklematestmodelplugin

INCLUDEPATH += $$BASEDIR/src/Tools $$BASEDIR/src/Gui $$BASEDIR/src/Model $$BASEDIR/src/MqttModule
DEPENDPATH += $$BASEDIR/src/Tools $$BASEDIR/src/Gui $$BASEDIR/src/Model $$BASEDIR/src/MqttModule



