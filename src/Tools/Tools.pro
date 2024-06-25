!include("$$BASEDIR/common.pri") {
    error("Не удалось подключить common.pri!")
}

QT -= gui

TEMPLATE = lib

SOURCES += \
    LogFormatter.cpp

HEADERS += \
    LogFormatter.h \
    Macros.h

DESTDIR = $$INSTALL_DIR/libs
