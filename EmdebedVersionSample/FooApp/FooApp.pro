TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
#CONFIG -= qt

# VERSIONを指定すると、qmake時リソースファイル(*.rc)が自動生成される
# (ただし、RC_FILEを指定していない場合に限る)

# windowsなら"major.minor.patch.build"形式固定
# (省略した箇所は0となる）
#VERSION = 1.2.3.4  # ファイルバージョン/製品バージョン
VERSION = 1.2.3  #=> "1.2.3.0"
QMAKE_TARGET_COMPANY = "izumisan"
QMAKE_TARGET_PRODUCT = "Foo"  # 製品名
QMAKE_TARGET_DESCRIPTION = "This is a description."  # ファイルの説明
QMAKE_TARGET_COPYRIGHT = "Copyright (c) 2021 izumisan All Rights Reserved."  # 著作権

# RC_ICONSにicoファイルを指定すると、プログラムアイコンとしてリソースファイルに登録される
RC_ICONS=github.ico

SOURCES += main.cpp
OTHER_FILES += github.ico
