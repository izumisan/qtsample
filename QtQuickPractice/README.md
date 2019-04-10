# Qt Quick

# overview

- HelloWorld
    - はじめてのQt Quickアプリケーション
- CppAccessQML
    - QML側要素をC++側からアクセスするサンプル
- QMLAccessCppMethod
    - C++オブジェクトをQML側にセットし、QML側からC++メソッドを呼び出すサンプル
- PropertyBinding
    - C++オブジェクトをQML側にセットし、QML側からC++getter/setterをプロパティとしてアクセスするサンプル
- PropertyBinding2
    - QML側でC++クラスをインポートし、QML側でインスタンスを生成するサンプル
    - プロパティバインド
- PropertyBinding3
    - QML側でC++クラスをインポートし、QML側でインスタンスを生成するサンプル
    - `Bindingエレメント`によるバインド
- PropertyBinding4
    - `Q_PROPERTY`マクロで自作クラスをQML側に公開したサンプル
- ConnectOnCpp
    - QMLシグナルとC++スロットをC++側でコネクトする
    - C++シグナルとQMLスロットをC++側でコネクトする
- ConnectOnQml
    - QMLシグナルとC++スロットをQML側でコネクトする
    - C++シグナルとQMLスロットをQML側でコネクトする
- ListViewSample
    - `ListModel`エレメントにより、QML側でListViewのモデルを指定
- ListViewSample2
    - C++側で生成した`QList<T>`モデルをListViewのモデルに指定
- ListViewSample3
    - `QQmlListProperty<T>`を利用したサンプル
- ListViewSample4
    - `QAbstractListModel`を利用したサンプル
    - C++側でインスタンスを生成しているパターン
- ListViewSample5
    - `QAbstractListModel`を利用したサンプル
    - `QAbstractListModel`のサブクラス自体をQML側に登録（`qmlRegisterType`）したパターン
- SingletonTypeProvider
    - `qmlRegisterSingletonType`により、QML内でのシングルトンクラスとして登録したサンプル
- CppEnumProvider
    - C++で定義した列挙型をQML側で利用できるようにしたサンプル
- JsonOnQML
    - C++側からJSON文字列をQML側に公開
    - QML側でJSON文字列をパースして利用

# Note: C++/QML連携

## C++からQML要素にアクセスする

- QMLエレメントに`objectName`プロパティで名前付け
- C++からアクセス
    - `property("name")`で値の取得
    - `setProperty("name", "value")`で値の設定

## C++オブジェクトをQMLにセットする（C++オブジェクトのエクスポート）

- QQmlContext::setContextProperty()
    ```cpp
    // QMLにfooオブジェクトをセット
    engine.rootContext()->setContextProperty( "foodata", &foo );
    ```

## C++メソッドをQMLから呼び出す（C++メソッドのエクスポート）

- C++メソッドを、`Q_INVOKABLE`マクロでエクスポートする
    ```cpp
    Q_INVOKABLE void exportMethod();
    ```

## C++ getter/setterメソッドをQMLプロパティとして使用する（C++ getter/setterのプロパティ化）

- C++ getter/setterメソッドを、`Q_PROPERTY`マクロでエクスポートする
    ```cpp
    Q_PROPERTY(int value READ value WRITE setValue NOTIFY valueChanged)
    ```

- リスト（配列）プロパティをエクスポートする場合は、`QQmlListProperty<T>`とする
    ```cpp
    Q_PROPERTY(QQmlListProperty<Foo> fooList READ fooList NOTIFY listSizeChanged)
    ```

## C++クラスをQMLエレメントとして使用する（C++クラスのエクスポート）

- qmlRegisterType()でC++クラスをエクスポートする
    ```cpp
    qmlRegisterType<Foo>( "FooLibrary", 1, 0, "Foo" );
    ```
- エクスポートしたC++クラスは`import`して使用する
    ```qml
    import FooLibrary 1.0
    ```

## プロパティバインディング

- `プロパティ1: プロパティ2`で、プロパティ2の値がプロパティ1に設定される
- `Binding`エレメントを使用する

## QMLシグナル

- `signal`でシグナルを定義する
    ```qml
    signal buttonClicked();  // QMLシグナル
    ```
- QMLシグナルの発行は、通常のメソッド呼び出しと同様
    ```qml
    onClicked: buttonClicked()  // QMLシグナルの発行
    ```

## QMLスロット

- 通常の関数定義でスロットとして利用できる
    ```qml
    function setLabelText( text ) { ... }
    ```

## C++とQMLでシグナルとスロットをコネクト

- C++側でコネクト
    - `SIGNAL`, `SLOT`マクロを使用して`QObject::connect()`でコネクトする
- QML側でコネクト
    - `Connections`エレメントでコネクトする
    - C++シグナルはQML側では、`on+シグナル名`となる
        - 例: [C++] fooUpdated = [QML] onFooUpdated
- C++シグナルの引数をQMLスロットで受け取る場合、引数の型は`QVariant`にする必要がある

## QMLでJSONをパース

```qml
var jsonstring = '{"name": "bar", "value": 1.234}'
var jsonobject = JSON.parse(jsonstring)

console.log( jsonobject.name )
console.log( jsonobject.value )
```

## Model - View - Delegate

- [Model Subclassing Reference - Qt Documentation](http://doc.qt.io/qt-5/model-view-programming.html#model-subclassing-reference)

## QAbstractListModelのサブクラス化

- `rowCount()`, `data()`をオーバーライドする
- `roleNames()`をオーバーライドする
- `setData()`, `flags()`をオーバーライドする
- データ追加の前に、`beginInsertRows()`を呼び出す。データ追加の後に、`endInsertRows()`を呼び出す。
- データ削除の前に、`beginRemoveRows()`を呼び出す。データ削除の後に、`endRemoveRows()`を呼び出す。
