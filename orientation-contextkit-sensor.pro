PLUGIN_TYPE = sensors
TEMPLATE = lib
QT = core dbus
CONFIG += plugin mobility link_pkgconfig
PKGCONFIG += contextprovider-1.0 contextsubscriber-1.0
MOBILITY += sensors 
TARGET = $$qtLibraryTarget(qtsensors_orientation)

HEADERS += \
    orientation.h
SOURCES += \
    orientation.cpp \
    plugin.cpp

plugin.files += libqtsensors_orientation.so
plugin.path += $$[QT_INSTALL_PLUGINS]/sensors
INSTALLS += plugin

VERSION = 0.0.3
PROJECT_NAME = orientation-contextkit-sensor

dist.commands += rm -fR $${PROJECT_NAME}-$${VERSION} &&
dist.commands += git clone . $${PROJECT_NAME}-$${VERSION} &&
dist.commands += rm -fR $${PROJECT_NAME}-$${VERSION}/.git &&
dist.commands += tar jcpvf $${PROJECT_NAME}-$${VERSION}.tar.bz2 $${PROJECT_NAME}-$${VERSION}
QMAKE_EXTRA_TARGETS += dist
