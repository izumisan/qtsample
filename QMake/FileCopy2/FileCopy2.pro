TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp

OTHER_FILES += \
    foo1.txt \
    foo2.txt \
    bar/bar1.txt \
    bar/bar2.txt

defineReplace(copyCommand2) {
    src = $$1
    dest = $$2

    arg1 = \"$$replace(src, /, $$QMAKE_DIR_SEP)\"
    arg2 = \"$$replace(dest, /, $$QMAKE_DIR_SEP)\"

    command = ""
    !equals(arg1, $$arg2) {
        command = $(COPY_FILE) $${arg1} $${arg2}
    }
    return($$command)
}

foo1.depends = $${PWD}/foo1.txt
foo1.target = $${OUT_PWD}/foo1.txt
foo1.commands = $$copyCommand2($$foo1.depends, $$foo1.target)
QMAKE_EXTRA_TARGETS += foo1
PRE_TARGETDEPS += $$foo1.target

foo2.depends = $${PWD}/foo2.txt
foo2.target = $${OUT_PWD}/foo2.txt
foo2.commands = $$copyCommand2($$foo2.depends, $$foo2.target)
QMAKE_EXTRA_TARGETS += foo2
PRE_TARGETDEPS += $$foo2.target

#bar1.depends = $${PWD}/bar/bar1.txt
#bar1.target = $${OUT_PWD}/bar/bar1.txt
#bar1.commands = $$copyCommand2($$bar1.depends, $$bar1.target)
#QMAKE_EXTRA_TARGETS += bar1
#PRE_TARGETDEPS += $$bar1.target
