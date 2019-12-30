# OpenCppCoverage on QTest

OpenCppCoverageをQtTestで使用する際の汎用スクリプトの試作プロジェクト

QtTestに対しOpenCppCoverageを使用する場合、QtにPATHを通していないとVisualStudioアドインからの起動ができずに、コマンドラインから実行する必要がある。

本プロジェクトは、この面倒なコマンドを毎回打たず、また、汎用的に使えるようにできないかを検討するためのプロジェクトである。

# 準備

QtとOpenCppCoverageへのPATH設定のため、以下の内容のファイルを`runcoverage.runenv`というファイル名で`makeruncoverage.ps1`と同階層に作成する
```
path/to/qt;path/to/opencppcoverage
```

# 仕組み

- ビルドイベント（正確にはリンクイベント）（QMAKE_PRE_LINK/QMAKE_POST_LINK）で、`makeruncoverage.ps1`を実行する
    - 引数に作業ディレクトリとテストプログラムを指定する
- `makeruncoverage.ps1`により、`runvoverage.ps1`が自動生成される
- この`runcoverage.ps1`を実行することにより、OpenCppCoverageによるテストが実行される
- OpenCppCoverage用のオプションは、`runcoverage.config`に指定する
