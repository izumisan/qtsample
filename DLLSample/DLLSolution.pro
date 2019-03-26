TEMPLATE = subdirs
CONFIG += orderd
SUBDIRS += \
    DLLSample \
    DLLLoader

DLLSample.depends = DLLLoader
