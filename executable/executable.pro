!include("$$BASEDIR/common.pri") {
    error("Не удалось подключить common.pri!")
}

QT += core qml

TARGET = PiklemaTest
DESTDIR = $$INSTALL_DIR

SOURCES += \
    main.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$INSTALL_DIR/libs/release/ -lCore -lTools -lMqttModule
else:win32:CONFIG(debug, debug|release): LIBS += -L$$INSTALL_DIR/libs/debug/ -lCore -lTools -lMqttModule
else:unix: LIBS += -L$$INSTALL_DIR/libs/ -lCore -lTools -lMqttModule

win32:CONFIG(release, debug|release): LIBS += -L$$INSTALL_DIR/qml/PiklemaTest/release/ -lpiklematestplugin
else:win32:CONFIG(debug, debug|release): LIBS += -L$$INSTALL_DIR/qml/PiklemaTest/debug/ -lpiklematestplugin
else:unix: LIBS += -L$$INSTALL_DIR/qml/PiklemaTest/ -lpiklematestplugin

win32:CONFIG(release, debug|release): LIBS += -L$$INSTALL_DIR/qml/PiklemaTest/Model/release/ -lpiklematestmodelplugin
else:win32:CONFIG(debug, debug|release): LIBS += -L$$INSTALL_DIR/qml/PiklemaTest/Model/debug/ -lpiklematestmodelplugin
else:unix: LIBS += -L$$INSTALL_DIR/qml/PiklemaTest/Model/ -lpiklematestmodelplugin

INCLUDEPATH += $$BASEDIR/src/Core $$BASEDIR/src/Tools $$BASEDIR/src/Gui $$BASEDIR/src/Model $$BASEDIR/src/MqttModule
DEPENDPATH += $$BASEDIR/src/Core $$BASEDIR/src/Tools $$BASEDIR/src/Gui $$BASEDIR/src/Model $$BASEDIR/src/MqttModule
