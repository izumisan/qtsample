# README

`State`エレメントによる状態遷移のサンプル

# overview

- StateSample
    - 状態遷移トリガを`when`で指定したサンプル
- StateSample2
    - 状態遷移トリガを`name`で指定したサンプル
- StateSample3
    - 状態遷移時に`StateChangeScript`を使用したサンプル

# 覚書

- `Item`の`states`プロパティで`State`を設定する
- `State`エレメントで状態を定義する
    - `when`で遷移条件（イベント/アクション）を指定
    - `name`で状態に名前付けが可能
- `State`エレメントの`state`プロパティで、現在の状態が取得・設定が可能
- `PropertyChanges`エレメントで遷移時の処理（プロパティ変更）を定義する
- `StateChagneScript`エレメントで遷移時に実行するスクリプト（関数呼び出し）を指定できる
