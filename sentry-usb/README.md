# Sentry-USB 導入ガイド

Tesla のセントリーモード用スマート USB ドライブ「Sentry-USB」を導入するための、日本国内ユーザー向けのクイックガイドです。詳細なドキュメントは [external/README.md](external/README.md) および [external/wiki](external/wiki/Home.md)（日本語訳済み）を参照してください。

## 1. 必要なハードウェア（機材）

Sentry-USB を動かすために、以下の機材を揃える必要があります。

- **Raspberry Pi 本体**:
    - **推奨**: **Raspberry Pi 4B または 5** (処理が速く、最も安定しています)
    - **廉価版**: **Raspberry Pi Zero 2 W** (小型で車内でも場所を取りませんが、処理は少し重めです)
- **microSD カード**:
    - **128GB 以上を推奨** (録画データの一時保存用)。
    - 書き換えに強い「高耐久（Endurance）」モデルが理想的です。
- **USB ケーブル（データ転送対応）**:
    - **注意**: 充電専用ケーブルでは車両が認識しません。必ずデータ転送可能なものを選んでください。
    - Pi 4/5 なら「USB-A to USB-C」、Pi Zero 2 W なら「USB-A to Micro-USB」が必要です。
- **(オプション) 外付け SSD**:
    - 保存容量を増やしたい場合、Pi 4/5 なら USB SSD を接続してデータ保存先に指定できます。

## 2. ネットワーク通信の仕組み

Sentry-USB は、状況に合わせて 3 つの通信方法を自動で使い分けます。

- **自宅 Wi-Fi (クライアントモード)**: 
    - 自宅の駐車場で、録画データを NAS やクラウド（Google Drive 等）へ自動転送します。
- **外出先 Wi-Fi (アクセスポイントモード)**: 
    - Pi 自体が Wi-Fi 親機（SSID: `SentryUSB`）になり、車内からスマホで Web UI にアクセスして録画をチェックできます。
- **Bluetooth LE (BLE)**: 
    - 初回の Wi-Fi 設定や、iOS アプリ「Sentry Connect」での簡易的なステータス確認に使用します。

## 3. セットアップの流れ

1. **OS イメージの作成**: PC で SD カードに専用イメージを書き込みます。
2. **車両に接続**: グローブボックス内の USB ポートに接続します。
3. **Web UI で設定**:
    - スマホや PC から `http://sentryusb.local`（自宅 Wi-Fi）または `http://192.168.66.1`（直接接続）を開きます。
    - 画面上の「セットアップウィザード」に従って、Wi-Fi と保存先を設定します。
4. **自動セットアップ開始**: 適用すると Pi が数回再起動し（約 10〜20 分）、完了すると Tesla が USB ドライブとして認識します。

## 4. 録画データの保存（アーカイブ）先

保存先として、以下のいずれかを選べます。

- **Windows 共有 (CIFS/SMB)**: 自宅の PC や NAS。
- **rclone (クラウド)**: Google Drive, Dropbox, Amazon S3, OneDrive など。
- **rsync**: Linux サーバー等。

## 💡 推奨アプリ
iPhone をお使いの場合、App Store から **[Sentry Connect](https://apps.apple.com/app/sentry-connect/id6759679030)** をインストールすると、プッシュ通知やライブアクティビティでの進捗確認ができて便利です。
