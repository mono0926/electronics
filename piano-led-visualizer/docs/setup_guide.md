# セットアップガイド (Software Setup)

[onlaj/Piano-LED-Visualizer](https://github.com/onlaj/Piano-LED-Visualizer) を動作させるための手順です。

## 1. 最短ルート: 専用OSイメージを使用する

最も簡単で推奨される方法です。

1. [Releases](https://github.com/onlaj/Piano-LED-Visualizer/releases) ページから最新の `.img` ファイルをダウンロードします。
2. **Raspberry Pi Imager** を使用して、MicroSDカードに書き込みます。
3. Raspberry Pi にセットして起動します。

## 2. 手動インストール (既存のOSを使用する場合)

Raspberry Pi OS Lite (64-bit 推奨) がインストールされている前提です。

```bash
# リポジトリのクローン
git clone https://github.com/onlaj/Piano-LED-Visualizer.git
cd Piano-LED-Visualizer

# インストールスクリプトの実行
sudo bash install.sh
```

## 3. 初期設定

### Wi-Fi接続

専用イメージを使用した場合、初回起動時に `Piano-LED-Visualizer` という名前のWi-Fiアクセスポイントが出現します。

- **Password**: `visualizer`
- 接続後、ブラウザで `http://192.168.4.1` にアクセスして設定画面を開きます。

### LEDの設定

Web UIの 「Settings」 から以下を設定します：

- **LED Count**: 実際に使用するLEDの数（例: 144）
- **LED Hardware**: GPIO 18 (デフォルト)
- **MIDI Input**: 接続した電子ピアノのデバイス名を選択
