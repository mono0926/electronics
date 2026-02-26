# ソフトウェアセットアップ・設定ガイド

このドキュメントでは、Raspberry Pi の OS インストールから Piano LED Visualizer の動作開始までの手順を解説します。

## 1. OS の書き込み (Raspberry Pi Imager)

**Raspberry Pi Imager** を使用して、設定を事前に済ませる（Headless セットアップ）のが最も効率的です。

- **OS 選択**: `Raspberry Pi OS (64-bit) Lite` (Zero 2 W の場合)
- **詳細設定 (歯車アイコン)**:
  - **ホスト名**: `pianoledvisualizer.local`
  - **SSH を有効化**: パスワード認証を使用
  - **ユーザー名とパスワードを設定**:
    - ユーザー名: `plv`
    - パスワード: `visualizer` (任意ですが、ドキュメントのデフォルトに合わせておくと楽です)
  - **Wi-Fi を設定**: 自宅の SSID とパスワードを入力。国コードは `JP`。
  - **ロケール設定**: タイムゾーン `Asia/Tokyo`、キーボードレイアウト `jp`。

## 2. 初回ログインとインストール

書き込みが終わったら SD カードをラズパイに指して電源を入れ、数分待ってから Mac のターミナルから接続します。

```bash
ssh plv@pianoledvisualizer.local
```

ログインできたら、以下の自動インストールスクリプトを実行します。

```bash
sudo bash -c "$(curl -fsSL https://raw.githubusercontent.com/onlaj/Piano-LED-Visualizer/master/autoinstall.sh)"
```

### インストールのポイント

- 途中で何度か再起動を求められる場合があります。
- スクリプトが完了すると、ラズパイ自体が Wi-Fi ホスポット（SSID: `PianoLEDVisualizer`）になるモードと、既存の Wi-Fi に繋がるモードが選べます。基本的には既存の Wi-Fi をそのまま使うのが便利です。

## 3. サービスの管理 (systemd)

プログラムは `visualizer.service` としてバックグラウンドで自動実行されます。手動で操作する際の主要コマンドは以下の通りです。

- **状態確認**: `sudo systemctl status visualizer.service`
- **再起動**: `sudo systemctl restart visualizer.service`
- **停止**: `sudo systemctl stop visualizer.service`
- **ログの確認**:
  - `sudo journalctl -u visualizer.service -f` (リアルタイムでエラー等を確認)

## 4. Web インターフェースへのアクセス

同じネットワーク内の PC やスマホから、以下の URL にアクセスして設定（LEDの色、明るさ、MIDIポートなど）を行います。

- **URL**: `http://pianoledvisualizer.local`
- **IPアドレス直接**: `http://(ラズパイのIPアドレス)`

---

## 5. Web インターフェースの詳細設定

ブラウザで `http://pianoledvisualizer.local` にアクセスして設定を行います。

### 5.1 「Settings」タブの勘所

- **LED Count**: 実際に繋いだLEDの数を正確に入力してください。多いとデータ送信時間が延びてレイテンシが増え、少ないと端が光りません。
- **MIDI Input**: 複数のMIDI機器がある場合、ここで電子ピアノを明示的に選択します。
- **Brightness**: 常時100%にすると電源負荷が高まるため、50-70%程度から始めるのが安全です。

## 6. トラブルシューティング (故障・不具合かな？と思ったら)

| 症状                     | 推測される原因                     | 対策                                            |
| :----------------------- | :--------------------------------- | :---------------------------------------------- |
| **LEDが全く光らない**    | GNDが共通化されていない / 配線ミス | ラズパイとLEDのGNDを再度確認する                |
| **色が激しく点滅する**   | 信号レベルの不足                   | レベルシフタ (74AHCT125) を導入する             |
| **末端の色が黄色っぽい** | 電圧降下                           | テープの反対側からも5V/GNDを供給する (電力注入) |
| **演奏と光がズレる**     | 処理負荷が高い                     | 不要なフォアグラウンドプロセスを停止する        |

### ハマりどころと対策

> [!CAUTION]
> **SPI の有効化**:
> 自動インストールで有効化されますが、もし点灯しない場合は `sudo raspi-config` > `Interface Options` > `SPI` が `Yes` になっているか確認してください。

> [!TIP]
> **Zero 2 W の熱**:
> 32bit OS よりも 64bit OS の方がパフォーマンスが良いですが、負荷がかかると熱を持ちやすくなります。後述のハードウェアガイドを参考に、適切な放熱対策（ヒートシンクやケース）を検討してください。

## 7. 発展：アニメーションモードの理解

本プロジェクトは単なる点灯だけでなく、以下のようなモードが楽しめます。

- **Velocity Mode**: 鍵盤を叩く強さに応じて、LEDの輝度や色を変化させます。
- **Fading**: 離鍵後に余韻を残すように消灯させます。
- **Background Layer**: 演奏していない時に、全体の雰囲気を盛り上げるバックグラウンドアニメーションを重畳させます。

> [!NOTE]
> アニメーションモードの詳細な種類や、Webインターフェースで設定できる全機能の図解辞典については、[主要機能 (外部ドキュメント)](https://github.com/mono0926/Piano-LED-Visualizer/blob/ja/Docs/features.md) を参照してください。完成後に「どんな風に光らせて遊べるか」を楽しむための必読ドキュメントです。
