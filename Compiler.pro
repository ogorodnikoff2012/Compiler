TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
	symbol.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
	symbol.h \
    symbol_type.h

