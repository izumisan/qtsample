# WPFLikeQtQuick

QtQuickでMVVM（WPF）するための部品作りに挑戦してみた

# RelayCommand

- STEP 1: RelayCommandSample
    - C++側でRelayCommandクラスを作成
    - QML側でバインド＆コネクトしたサンプル
- STEP 2: RelayCommandSample2
    - QML側のバインド＆コネクトを`Command`エレメントとしてコンポーネント化
- STEP 3: RelayCommandSample3
    - コマンドを非同期で実行する`RelayAsyncCommand`を試作
- TODO: `canExecuteChanged`シグナルを定期的に発火する仕組み検討
