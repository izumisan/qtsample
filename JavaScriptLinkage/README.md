# JavaScript連携サンプル

# Overview

- JavaScriptLinkage
    - QMLからJavaScriptを利用したサンプル
- JavaScriptLinkage2
    - QMLからJavaScriptをステートレスとして利用したサンプル

# Note

- QMLからJSファイルをインポート
    ```qml
    import "foo.js" as Foo
    ```
- JSファイルからJSファイルをインポート
    ```js
    Qt.include("bar.js")
    ```
- ステートレスライブラリ
    - jsファイルに`.pragma library`を指定することでステートレスライブラリとなり、jsインスタンスがアプリ間で共有される
    - 非ステートレスの場合、`import`毎に別インスタンスとなる
