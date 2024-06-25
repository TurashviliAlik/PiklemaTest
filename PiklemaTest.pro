TEMPLATE = subdirs

CONFIG += ordered

SUBDIRS += \
    libs/qtmqtt \
    src \
    executable

# SUBDIRS += \
#     src \
#     tests \
#     executable

DISTFILES += \
    .qmake.conf \
    common.pri
