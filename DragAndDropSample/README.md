# ドラッグ&ドロップ サンプル

# overview

- DragAndDropSample
    - ドラッグ＆ドロップの最小サンプル
- DragAndDropSample2
    - ドラッグキーによるドラッグアイテムを弁別したサンプル

# 覚書

- `Drag.active: bool`
    - activeの時、ドラッグアイテムのイベント（PositionChanged等）がDropAreaで処理され、enter/exit等の判定が行われる
- `Drag.hotSpot: QPointF`
    - DropAreaとの衝突判定に用いれるポイント（1ピクセル）
    - デフォルトは(0,0)の左上
    - hotSpotではなくドラッグアイテムと接した際にEnter/Exit判定をしたい場合は、DropArea自体をドラッグアイテムの大きさを考慮して、大き目に設定すればよい
