# testshared.pri

INCLUDEPATH += $${PWD}/shared
HEADERS += $${PWD}/shared/*.h

QMAKE_POST_LINK += powershell -ExecutionPolicy RemoteSigned -file \"$${PWD}/makeruncoverage.ps1\" $${OUT_PWD} $${OUT_PWD}/debug/$${TARGET}.exe;
