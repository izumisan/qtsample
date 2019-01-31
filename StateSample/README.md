# README

`State`エレメントによる状態遷移のサンプル

# overview

- StateSample
    - `when`による状態遷移
- StateSample2
    - `name`による状態遷移


# 覚書

- `Item`の`states`プロパティで`State`を設定する
- `State`エレメントで状態を定義する
    - `when`で遷移条件（イベント/アクション）を指定
    - `name`で状態に名前付けが可能
- `State`エレメントの`state`プロパティで、現在の状態が取得・設定が可能
- `PropertyChanges`エレメントで遷移時の処理（アクティビティ）を定義する
