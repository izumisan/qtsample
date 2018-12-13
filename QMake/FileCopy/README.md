# FileCopy

## qmake用ファイルコピーコマンド生成関数

```
defineReplace(copyCommand){
    src = $$1
    dest = $$2
    return($(COPY_FILE) \"$$replace(src, /, $$QMAKE_DIR_SEP)\" \"$$replace(dest, /, $$QMAKE_DIR_SEP)\")
}
```

## 使い方（ビルド時にファイルコピーされる）

```
readme.depends = $$_PRO_FILE_PWD_/README.md
readme.target = $$OUT_PWD/README.md
readme.commands = $$copyCommand($${readme.depends}, $${readme.target})
QMAKE_EXTRA_TARGETS += readme
PRE_TARGETDEPS += $$readme.target
```
