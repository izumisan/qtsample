# WPFLikeQtQuick

QtQuickでMVVM（WPF）するための部品を試作する検討用プロジェクト

# RelayCommand

- STEP 1: RelayCommandSample
    - C++側でRelayCommandクラスを作成
    - QML側でバインド＆コネクトしたサンプル
- STEP 2: RelayCommandSample2
    - QML側のバインド＆コネクトを`Command`エレメントとしてコンポーネント化
- STEP 3: RelayCommandSample3
    - コマンドを非同期で実行する`RelayAsyncCommand`を試作
- STEP 4: RelayCommandSample4
    - `canExecuteChanged`シグナルの発行を助ける`CommandManager`の試作プロジェクト

# ObservableProperty

- STEP 1: ObservableProperty
    - QML側に公開するプロパティクラスの試作プロジェクト
- STEP 2: ObservableProperty2
    - `ObservableProperty<T>`にカスタムクラスを指定した動作確認
    - ObservableProperty用getter/setterを提供するヘルパークラスの試作
- STEP 3: ObservableProperty3
    - `ObservableProperty<T>`に`subscribe()`, `unsubscribe()`を追加したサンプル

# ObservableCollection

- STEP 1: ObservableCollection
    - QAbstractListModel型のテンプレートクラスの試作
- STEP 2: ObservableCollection2
    - `ObservableCollection<T>`にカスタムクラスを指定した動作確認＆アップデート

# ViewModelBase

- ViewModelBase
    - ViewModelBaseクラスの試作

# InteractionRequest

- InteractionRequestPrototype
    - Messengerによるダイアログサービスの試作プロジェクト
- InteractionRequestPrototype2
    - Messengerによるダイアログサービスの試作プロジェクト その2
    - ダイアログを動的に生成する
