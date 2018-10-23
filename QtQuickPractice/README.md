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
- ConnectOnCpp
    - QMLシグナルとC++スロットをC++側でコネクトする
    - C++シグナルとQMLスロットをC++側でコネクトする
- ConnectOnQml
    - QMLシグナルとC++スロットをQML側でコネクトする
    - C++シグナルとQMLスロットをQML側でコネクトする
- ListViewSample
    - `ListModel`エレメントにより、QML側でListViewのモデルを指定
- ListViewSample2
    - C++側で生成したモデルをListViewのモデルに指定

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
- C++シグナルの引数をQMLスロットで受け取る場合、引数の型は`QVariant`にする必要がある
