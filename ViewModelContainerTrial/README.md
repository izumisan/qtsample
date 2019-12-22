# ViewModelContainerTrial

QML用のViewModelコンテナを試作するプロジェクト

# overview

- ViewModelContainerTrial
    - ViewModelを`std::shared_ptr<T>`で保持したパターン
- ViewModelContainerTrial2
    - ViewModelを`std::any`で保持したパターン
    - `std::any`から値を取り出す時に元の型が必要になるので、QMLから取得できずに微妙に使いづらい...
- ViewModelContainerTrial3
    - Trial2と同様、ViewModelを`std::any`で保持
    - QMLからのアクセス用に`QObject*`の取得関数を追加で保持したパターン
    - 手抜きして`std::tuple`で実装しているのでかなりひどいことになっているが、動作的に問題はなさそう？
