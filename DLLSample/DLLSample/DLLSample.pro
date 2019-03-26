QT -= gui

TARGET = foobar
TEMPLATE = lib

CONFIG += dll
CONFIG -= lib_bundle
CONFIG += c++14

msvc: include(msvc.pri)

DLLTOP = $${PWD}
INCDIR = $${DLLTOP}/include/
SRCDIR = $${DLLTOP}/src/

CONFIG(debug, debug|relase) {
    DESTDIR = $${DLLTOP}/lib/debug/
} else {
    DESTDIR = $${DLLTOP}/lib/release/
}
DLLDESTDIR = $${DLLTOP}/../bin/

DEFINES += FOOLIBRARY_EXPORTS
DEFINES += BARLIBRARY_EXPORTS

INCLUDEPATH += \
    $${INCDIR} \
    $${SRCDIR}

HEADERS += \
    $${INCDIR}/*.h \
    $${SRCDIR}/*.h

SOURCES += \
    $${SRCDIR}/*.cpp

# モジュール定義ファイル
DEF_FILE += $${DLLTOP}/barlibrary.def
