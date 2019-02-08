# README

QtQcuickでアニメーションのサンプル

# overview

- AnimationSample
    - `NumberAnimation`でフォントサイズをアニメーションさせる単純なサンプル
- AnimationSample2
    - `Behavior`エレメントで、プロパティ変化にアニメーションを実行するサンプル
- AnimationSample3
    - `Transition`エレメントで、状態遷移にアニメーションを実行するサンプル
- AnimationSample4
    - `Transition`エレメントの`from`, `to`プロパティで、アニメーションを実行する状態遷移に条件付けしたサンプル
- AnimationSample5
    - `SequentialAnimation`, `ParallelAnimation`で、複数のアニメーションを組み合わせて実行したサンプル
- AnimationControl
    - アニメーション実行を制御するサンプル

# アニメーションタイプ

- AnchorAnimation
- ParentAnimation
- PathAnimation
- ColorAnimation
    - `color`に対するアニメーション
- NumberAnimation
    - `qreal`に対するアニメーション
- PropertyAnimation
- RotationAnimation
    - `rotation`に対するアニメーション
- Vector3dAnimation
    - `vector3d`に対するアニメーション

# アニメーション遷移

- Transition
    - Stateが変化した時、指定したアニメーションを実行する
- SequentialAnimation
    - 複数のアニメーションを連続実行する
- ParallelAnimation
    - 複数のアニメーションを並列実行する
- Behavior
    - プロパティが変化した時、指定したアニメーションを実行する
- PropertyAction
    - アニメーション実行中に指定したプロパティを変更する. 
    - `PropertyAction`によるプロパティ変化では、アニメーションは実行されない
- SmoothedAnimation
- SpringAnimation
- ScriptAnimation
    - アニメーション実行中に指定したスクリプト（関数）を実行する

# アニメーション制御

- start
- pause
- resume
- restart
- stop
- complete
