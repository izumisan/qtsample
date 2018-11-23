# README

QtQuickアプリケーションの標準構成やモジュールのインポートなどの検討用

# 覚書

- リソースファイル名はアプリケーション名に合わせる
- qmlファイルはリソースに含める
- qmlファイルの配置は、`/qml/<AppName>/main.qml`とする
- モジュールをインポートする場合は、インポートパスを設定する
    ```cpp
    engine.addImportPath(QStringLiteral("qrc:/qml"));
    ```
- `QML_IMPORT_PATH`は、QtCreator上の設定で、ビルド等には影響しない？
    - `QML_IMPORT_PATH`を設定しなくても場合、インポートモジュールが見つからないと破線が表示されるがビルド・実行は可能
