# 徹底網羅：部品・工具リスト (Exhaustive BOM) - Piano LED Visualizer

このプロジェクトを安全かつ高品質に完成させるための、全パーツと推奨工具のリストです。

## A. コア電子部品 (Core Electronics)
これがないと始まらない、システムの心臓部です。

| 部品名 | 推奨モデル | ポイント | 調達先 (国内優先) |
| :--- | :--- | :--- | :--- |
| **Microcontroller** | Raspberry Pi Zero 2 WH | 4コアの高速版。ヘッダー付き(WH)が組立やすく推奨。 | [秋月電子](https://akizukidenshi.com/catalog/g/g129607/) |
| **LED Strip** | WS2812B (144 LEDs/m) | **5V, IP30(非防水), 黒基板**。ピアノ88鍵には1.5m〜2m必要。 | [Amazon](https://www.amazon.co.jp/s?k=WS2812B+144+leds) / [AliExpress](https://ja.aliexpress.com/item/1005007989207832.html) |
| **Power Supply** | ACアダプタ 5V 6.2A | PSE取得済み。144LEDを50%輝度で駆動するのに最適。 | [秋月電子](https://akizukidenshi.com/catalog/g/g111105/) |
| **DC Jack Adapter** | メタルボディ・ネジ端子式 | 頑丈な金属製。ACアダプタの出力を安全に配線へ分岐。 | [秋月電子](https://akizukidenshi.com/catalog/g/g108851/) |
| **Level Shifter** | SN74AHCT125N (DIP-14) | ラズパイの3.3V信号を5Vに増幅。チラつき防止に必須。 | [マルツ](https://www.marutsu.co.jp/pc/i/14226373/) / [AliExpress](https://ja.aliexpress.com/item/1005010466137824.html) |
| **LCD Display** | 1.44inch TFT (ST7735) | 128x128px, SPI接続。IPアドレスや状態表示用。 | [Amazon](https://www.amazon.co.jp/dp/B07S8P8Y5C) |

## B. 安全・安定化パーツ (Safety & Protection)
火災防止と動作安定のための「影の主役」です。

| 部品名 | スペック | 役割 | 調達先 |
| :--- | :--- | :--- | :--- |
| **Inline Fuse Holder** | 平型ヒューズ用 (12~16AWG) | 電源ラインに挿入。異常時の発火を防止。 | [秋月電子](https://akizukidenshi.com/catalog/g/g105436/) / [Amazon](https://www.amazon.co.jp/dp/B08L7V4QW6) |
| **Blade Fuse** | **10A** (平型) | 万が一のショート時に回路を遮断。 | [秋月電子](https://akizukidenshi.com/catalog/g/g104900/) |
| **Capacitor** | 1000μF 6.3V以上 (電解) | LED電源入力部に入れ、突入電流を平滑化。 | [秋月電子](https://akizukidenshi.com/catalog/g/g100147/) |
| **Resistor** | 330Ω 〜 470Ω | データ線の始点に入れ、信号の反射ノイズを抑制。 | [秋月電子](https://akizukidenshi.com/catalog/g/g102283/) |

## C. 配線・接続パーツ (Wiring & Connectivity)
「これがないと作業が止まる」部材たちです。

| 部品名 | 推奨仕様 | 役割 | 調達先 |
| :--- | :--- | :--- | :--- |
| **Silicon Wire (厚)** | **18AWG** (赤・黒) | 電源ライン用。10Aを流しても熱くならない太さ。 | [Amazon](https://www.amazon.co.jp/dp/B07G76CGLR) |
| **Silicon Wire (細)** | **24〜26AWG** (各色) | 信号ライン用。柔らかく取り回しが良い。 | [Amazon](https://www.amazon.co.jp/dp/B07G29L8X2) |
| **Connectors** | JST-SM 3-pin | LEDストリップの着脱を容易に。 | [Amazon](https://www.amazon.co.jp/dp/B0716D9XJF) |
| **Heat Shrink Kit** | 各種サイズセット | はんだ付け箇所の絶縁。ライター等で熱収縮。 | [Amazon](https://www.amazon.co.jp/dp/B08XJSM9KG) |
| **Universal PCB** | Dタイプ (47x36mm) | レベルシフタIC等の実装台座。 | [秋月電子](https://akizukidenshi.com/catalog/g/g100015/) |
| **IC Socket** | 14ピン用 (DIP) | ICを直接はんだ付けせず、交換可能にする。 | [秋月電子](https://akizukidenshi.com/catalog/g/g101382/) |
| **Standoff Kit** | M2.5 ナイロン製 | ラズパイや基板の固定用。 | [Amazon](https://www.amazon.co.jp/dp/B06XZ7F9PR) |
| **Mounting Tape** | 3M 超強力両面テープ | アルミプロファイルをピアノに固定。 | [Amazon](https://www.amazon.co.jp/dp/B01B79Y6QO) |

## D. 筐体・外装パーツ (Structure & Housing)
美しく機能的な完成形を目指すための部材です。

| 部品名 | 詳細 | ポイント |
| :--- | :--- | :--- |
| **Aluminum Profile** | U型・ディフューザー付き | **放熱**と**光の拡散**。2m分必要。 | [Amazon](https://www.amazon.co.jp/dp/B07H8H187N) |
| **3D Print Filaments** | PLA / PETG (黒/白) | コンソールケースの印刷用。Bambu Lab P2Sで出力。 |
| **USB OTG Hub** | Micro USB ⇔ USB-A x2以上 | ピアノからのMIDI信号をラズパイに入力。 | [Amazon](https://www.amazon.co.jp/dp/B00NHA7S2M) |
| **MicroSD Card** | 16GB〜32GB (High Speed) | OSおよび楽曲データ用。 | [Amazon](https://www.amazon.co.jp/dp/B07SC7BZHR) |
| **HDMI Adapter** | Mini-HDMI to HDMI | 初期設定やデバッグ用。 | [Amazon](https://www.amazon.co.jp/dp/B006V7S4M8) |

## E. 必須・推奨ツール (Tools)
作業効率とクオリティを左右する道具です。

| 道具名 | 推奨品 / 条件 | 役割 |
| :--- | :--- | :--- |
| **Soldering Iron** | HAKKO FX-600 等 (温度調節付) | 日本の電子工作のデファクト。 |
| **Wire Stripper** | **Vessel 3500E-2** | シリコン線の被覆を傷つけず剥く。神ツール。 |
| **Multimeter** | **Sanwa PM-3** または **HIOKI 3244-60** | 電圧チェック、導通確認に必須。ないと詰みます。 |
| **Breadboard** | ミニサイズ | はんだ付け前の動作検証用。 |
| **Solder Wire** | 0.6〜0.8mm径 (鉛入り推奨) | 初心者には鉛入りの方が濡れ性が良く失敗が少ない。 |

---
### 💡 製作のアドバイス

- **ACアダプタの保護**: ヒューズは必ずACアダプタに近い側に配置してください。
- **テスターの重要性**: はんだ付けが終わるたびに、VCCとGNDがショートしていないかテスターで「導通チェック」する癖をつけましょう。これでラズパイを焼くリスクが激減します。
- **熱対策**: 144LED/mはそれなりに熱を持ちます。アルミプロファイルへの貼り付けは、LEDを長持ちさせるためにも非常に有効です。
