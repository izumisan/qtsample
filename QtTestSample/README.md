# QtTest

# 実行順序

- initTestCase
    - init
    - テストメソッド_1
    - cleanup
    - init
    - テストメソッド_2
    - cleanup
- cleanupTestCase
