# EmdebedVersion sample

バージョン番号やその他情報をプログラムに埋め込むサンプル

# 備忘録

- windowsの場合、`VERSION`を指定することで、qmake時にリソースファイル(*.rc)が自動生成され、プログラムバージョンが埋め込まれる
    - バージョン形式は `{major}.{minor}.{patch}.{build}`
- .exe or .dll の場合に適用される（.libには不可っぽい）
