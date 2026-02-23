# 徹底網羅：部品・工具リスト (Exhaustive BOM) - Piano LED Visualizer

このプロジェクトを安全かつ高品質に完成させるための、全パーツと推奨工具のリストです。
リンク切れに備え、商品名・型番・検索キーワードを中心に構成しています。

## A. コア電子部品 (Core Electronics)

| 部品名 | 推奨モデル/型番 | 検索キーワード (Amazon/AliExpress) | 調達先 (国内優先) |
| :--- | :--- | :--- | :--- |
| **Microcontroller** | Raspberry Pi Zero 2 WH | `Raspberry Pi Zero 2 WH` | [秋月 (129607)](https://akizukidenshi.com/catalog/g/g129607/) / [KSR](https://www.ksyic.com/) |
| **LED Strip** | WS2812B (144 LEDs/m) | `WS2812B 144 leds 5V IP30 black PCB` | [Amazon](https://www.amazon.co.jp/s?k=WS2812B+144+leds+5V) / [AliExpress](https://ja.aliexpress.com/item/1005007989207832.html) |
| **Level Shifter** | SN74AHCT125N | `SN74AHCT125N DIP-14` | [秋月 (104313)](https://akizukidenshi.com/catalog/g/g104313/) / [AliExpress](https://ja.aliexpress.com/item/1005010466137824.html) |
| **LCD Display** | 1.44" TFT (ST7735) | `1.44 inch TFT LCD ST7735 SPI` | [秋月 (116135)](https://akizukidenshi.com/catalog/g/g116135/) / [AliExpress](https://ja.aliexpress.com/item/1005006209100114.html) |

## B. 電源・安全・安定化 (Power & Safety)

| 部品名 | スペック/型番 | 検索キーワード / 備考 | 調達先 |
| :--- | :--- | :--- | :--- |
| **AC Adapter** | 5V 6.2A (LTE36ES-S1-301) | `5V 6A AC Adapter 5.5mm 2.1mm` | [秋月 (111105)](https://akizukidenshi.com/catalog/g/g111105/) |
| **DC Jack Adapter** | ネジ端子式 | `DC Jack Adapter 5.5mm 2.1mm Terminal` | [秋月 (108851)](https://akizukidenshi.com/catalog/g/g108851/) |
| **Fuse Holder** | ネジ止め/パネルマウント | `Fuse Holder 5x20mm` | [秋月 (100112)](https://akizukidenshi.com/catalog/g/g100112/) |
| **Glass Fuse** | **10A** (5.2x20mm) | `Glass Fuse 10A 250V 5x20mm` | [秋月 (104900)](https://akizukidenshi.com/catalog/g/g104900/) |
| **Capacitor** | 1000μF 10V以上 (電解) | `Electrolytic Capacitor 1000uF 10V` | [秋月 (100147)](https://akizukidenshi.com/catalog/g/g100147/) |
| **Resistor** | 330Ω 〜 470Ω | `Resistor 1/4W 330 ohm` | [秋月 (102283)](https://akizukidenshi.com/catalog/g/g102283/) |

## C. 配線・接続部材 (Wiring & Connectivity)

| 部品名 | 推奨仕様 | 検索キーワード / 備考 | 調達先 |
| :--- | :--- | :--- | :--- |
| **Silicon Wire (厚)** | **18AWG** (赤・黒) | `18AWG Silicone Wire Red Black` | [Amazon](https://www.amazon.co.jp/s?k=18AWG+シリコンケーブル) |
| **Silicon Wire (細)** | **24〜26AWG** | `24AWG Silicone Wire Multi Color` | [Amazon](https://www.amazon.co.jp/s?k=24AWG+シリコンケーブル) |
| **Connectors** | JST-SM 3-pin | `JST-SM 3 pin connector kit` | [Amazon](https://www.amazon.co.jp/dp/B0716D9XJF) |
| **Universal PCB** | 片面/両面 Dタイプ等 | `Universal Prototype Board 4x6cm` | [秋月 (100015)](https://akizukidenshi.com/catalog/g/g100015/) |
| **IC Socket** | 14ピン用 (DIP) | `14 pin DIP IC Socket` | [秋月 (101382)](https://akizukidenshi.com/catalog/g/g101382/) |
| **Aluminum Profile** | U型・2m分 | `LED Aluminum Profile U-shape 1m` | [Amazon](https://www.amazon.co.jp/dp/B07H8H187N) |

## D. その他・周辺機器 (Others)

| 部品名 | 備考 | 調達先 (例) |
| :--- | :--- | :--- |
| **USB OTG Hub** | MIDI接続に使用 | [Amazon](https://www.amazon.co.jp/dp/B00NHA7S2M) |
| **MicroSD Card** | 16GB〜32GB | [Amazon](https://www.amazon.co.jp/dp/B07SC7BZHR) |
| **HDMI Adapter** | Mini-HDMI to HDMI | [Amazon](https://www.amazon.co.jp/dp/B006V7S4M8) |
| **Mounting Tape** | 3M 超強力等 | [Amazon](https://www.amazon.co.jp/dp/B01B79Y6QO) |

## E. 必須・推奨工具 (Tools)

| 道具名 | 推奨品 / 型番 | 役割 |
| :--- | :--- | :--- |
| **Soldering Iron** | HAKKO FX-600 | 温度調節付。日本での定番。 |
| **Wire Stripper** | **Vessel 3500E-2** | シリコン線に最適。作業効率が劇的に向上。 |
| **Multimeter** | Sanwa PM-3 / HIOKI 3244-60 | 電圧チェック、導通確認に必須。 |
| **Solder Wire** | 0.6〜0.8mm径 (鉛入り) | 初心者には鉛入りの方が扱いやすい。 |

---

### 💡 製作のアドバイス

- **ACアダプタの保護**: ヒューズは必ずACアダプタの直後（VCC側）に配置してください。
- **テスターの重要性**: はんだ付けが終わるたびに、VCCとGNDがショートしていないか「導通チェック」してください。
- **熱対策**: 144LED/mは熱を持ちやすいため、アルミプロファイルへの貼り付けを強く推奨します。
