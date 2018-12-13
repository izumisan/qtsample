TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp

OTHER_FILES += README.md

# proファイルディレクトリ
message($$_PRO_FILE_PWD_)

# 出力先ディレクトリ
# （シャドウビルドディレクトリを取得できる）
message($$OUT_PWD)

# ディレクトリセパレーター
# （win: ￥）
message($$QMAKE_DIR_SEP)

message($$QMAKE_COPY_FILE)
message($$QMAKE_COPY_DIR)
message($$QMAKE_MKDIR_CMD)

#!equals(_PRO_FILE_PWD_, $$OUT_PWD) {
#    # コピー先
#    readme.target = $$OUT_PWD/README.md
#    # 対象ファイル
#    readme.depends = $$_PRO_FILE_PWD_/README.md
#    # コピーコマンドの作成（/を￥に置換）
#    readme.commands = $(COPY_FILE) \"$$replace(readme.depends, /, $$QMAKE_DIR_SEP)\" \"$$replace(readme.target, /, $$QMAKE_DIR_SEP)\"
#    QMAKE_EXTRA_TARGETS += readme
#    PRE_TARGETDEPS += $$readme.target
#}

defineReplace(copyCommand){
    src = $$1
    dest = $$2

    !equals(src, $$dest){
        message("copy")
    } else {
        message("NO copy")
    }

    return($(COPY_FILE) \"$$replace(src, /, $$QMAKE_DIR_SEP)\" \"$$replace(dest, /, $$QMAKE_DIR_SEP)\")
}

readme.depends = $$_PRO_FILE_PWD_/README.md
readme.target = $$OUT_PWD/README.md
readme.commands = $$copyCommand($${readme.depends}, $${readme.target})

message("---copyCommand---")
message($${readme.depends})
message($${readme.target})
message($${readme.commands})

!equals(readme.depends, $$readme.target) {
    QMAKE_EXTRA_TARGETS += readme
    PRE_TARGETDEPS += $$readme.target
}

message($$QMAKE_EXTRA_TARGETS)
