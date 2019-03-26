QT -= gui

TEMPLATE = app
CONFIG += c++11 console
CONFIG -= app_bundle

msvc: include(msvc.pri)

PROJECT_TOP = $${PWD}
DLLDIR = $${PROJECT_TOP}/../DLLSample/

CONFIG(debug, debug|release) {
    LIBS += -L$$quote($${DLLDIR}/lib/debug)
} else {
    LIBS += -L$$quote($${DLLDIR}/lib/release)
}
LIBS += -lfoobar

INCLUDEPATH += $${DLLDIR}/include/

HEADERS += \
    $${DLLDIR}/include/*.h

SOURCES += \
    main.cpp
