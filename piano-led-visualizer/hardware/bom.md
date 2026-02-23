# 徹底網羅：部品・工具リスト (Exhaustive BOM) - Piano LED Visualizer

このプロジェクトを安全かつ高品質に完成させるための、全パーツと推奨工具のリストです。
リンク切れに備え、商品名・型番・検索キーワードを中心に構成しています。

## A. コア電子部品 (Core Parts)

| 部品名               | 推奨モデル/型番        | 検索キーワード (Amazon/AliExpress)   | 調達先 (国内優先)                                                                                                                  |
| :------------------- | :--------------------- | :----------------------------------- | :--------------------------------------------------------------------------------------------------------------------------------- |
| **マイコン**         | Raspberry Pi Zero 2 WH | `Raspberry Pi Zero 2 WH`             | [秋月 (129607)](https://akizukidenshi.com/catalog/g/g129607/) / [KSR](https://www.ksyic.com/)                                      |
| **LEDテープ**        | WS2812B (144 LEDs/m)   | `WS2812B 144 leds 5V IP30 black PCB` | [Amazon](https://www.amazon.co.jp/s?k=WS2812B+144+leds+5V) / [AliExpress](https://ja.aliexpress.com/item/1005007989207832.html)    |
| **レベルシフタ**     | SN74AHCT125N           | `SN74AHCT125N DIP-14`                | [秋月 (104313)](https://akizukidenshi.com/catalog/g/g104313/) / [AliExpress](https://ja.aliexpress.com/item/1005010466137824.html) |
| **液晶ディスプレイ** | 1.44" TFT (ST7735)     | `1.44 inch TFT LCD ST7735 SPI`       | [秋月 (116135)](https://akizukidenshi.com/catalog/g/g116135/) / [AliExpress](https://ja.aliexpress.com/item/1005006209100114.html) |

## B. 電源・安全・安定化 (Power & Safety)

| 部品名               | スペック/型番         | 検索キーワード / 備考                  | 調達先                                                                                                            |
| :------------------- | :-------------------- | :------------------------------------- | :---------------------------------------------------------------------------------------------------------------- |
| **ACアダプタ**       | 5V 10A (BTF-LIGHTING) | `5V 10A AC Adapter 5.5mm 2.1mm`        | [Amazon](https://www.amazon.co.jp/dp/B085292P65)                                                                  |
| **DCジャック変換**   | ネジ端子式            | `DC Jack Adapter 5.5mm 2.1mm Terminal` | [秋月 (108851)](https://akizukidenshi.com/catalog/g/g108851/)                                                     |
| **ヒューズホルダー** | ガラス管用 (中継用)   | 10A電源系を組むなら必須                | [秋月 (P-109629)](https://akizukidenshi.com/catalog/g/g109629/)                                                   |
| **ヒューズ**         | **7.5A**              | ガラス管(32mm)。10A電源保護に最適      | [秋月 (P-107138)](https://akizukidenshi.com/catalog/g/g107138/)                                                   |
| **電解コンデンサ**   | 1000μF 10V以上        | `Electrolytic Capacitor 1000uF 10V`    | [秋月 (108424)](https://akizukidenshi.com/catalog/g/g108424/)                                                     |
| **抵抗器**           | 330Ω 〜 470Ω          | `Resistor 1/4W 330 ohm`                | [Amazon (GOODCHIセット)](https://amzn.to/4s2Hx6a) / [秋月 (125331)](https://akizukidenshi.com/catalog/g/g125331/) |

## C. 配線・接続部材 (Wiring)

| 部品名                   | 推奨仕様                           | 検索キーワード / 備考                                         | 調達先                                                                                                        |
| :----------------------- | :--------------------------------- | :------------------------------------------------------------ | :------------------------------------------------------------------------------------------------------------ |
| **シリコンケーブル(厚)** | **18AWG** (赤・黒)                 | `18AWG Silicone Wire Red Black` **(各3m〜5m推奨)**            | [Amazon](https://www.amazon.co.jp/s?k=18AWG+シリコンケーブル)                                                 |
| **シリコンケーブル(細)** | **24〜26AWG**                      | `24AWG Silicone Wire Multi Color` **(6色以上推奨、各1.5m〜)** | [Amazon](https://www.amazon.co.jp/s?k=24AWG+シリコンケーブル)                                                 |
| **中継コネクタ**         | JST-SM 3ピン                       | `JST-SM 3 pin connector kit` **(1〜2ペア使用)**               | [Amazon](https://www.amazon.co.jp/dp/B0716D9XJF)                                                              |
| **熱収縮チューブ**       | 各種サイズセット                   | **配線の絶縁に必須**。                                        | [Amazon](https://www.amazon.co.jp/s?k=熱収縮チューブ+セット)                                                  |
| **ユニバーサル基板**     | Raspberry Pi ZERO用                | `AE-RasPi-Universal-Zero`                                     | [秋月 (114031)](https://akizukidenshi.com/catalog/g/g114031/)                                                 |
| **連結ピンソケット**     | 2x20 (スタッキング用)              | **基板を二段重ねにするために必須**                            | [秋月 (11270)](https://akizukidenshi.com/catalog/g/g11270/)                                                   |
| **ICソケット**           | 14ピン用 (DIP)                     | レベルシフタ(SN74AHCT125N)の着脱・保護に使用                  | [秋月 (100028)](https://akizukidenshi.com/catalog/g/g100028/)                                                 |
| **アルミフレーム**       | U型プロファイル (既製品)           | 1m×5本〜10本セット。乳白カバー付きですぐに使えます。          | [Muzata (Amazon)](https://www.amazon.co.jp/dp/B01MXWL3X9)                                                     |
| **アルミフラットバー**   | **2mm厚 × 15〜20mm幅**             | **推奨案**。加工しやすく放熱も優秀。3Dプリント部材と併用。    | [ホームセンター(カインズ等)](https://www.cainz.com/g/4977720020150.html)                                       |
| **シリコンチューブ**     | ネオンLED用スリーブ (10/12mm)      | アルミ板の上に乗せて拡散用。粒感が消えて美しくなります。      | [AliExpress](https://ja.aliexpress.com/item/1005001391696086.html)                                             |
| **3Dプリントパーツ**     | マウント/ジョイント                | **Bambu Lab P2S** で自作。アルミ板をピアノに固定する部品。    | [参考モデル (Printables)](https://www.printables.com/search/models?q=piano+led)                               |

## D. その他・周辺機器 (Others)

| 部品名               | 備考                          | 調達先 (例)                                                                     |
| :------------------- | :---------------------------- | :------------------------------------------------------------------------------ |
| **USBハブ(OTG)**     | MIDIキーボード接続(Micro-USB) | [AliExpress (3 in 1 hub)](https://ja.aliexpress.com/item/1005007204961807.html) |
| **microSDカード**    | 16GB〜32GB                    | [Amazon](https://www.amazon.co.jp/dp/B07SC7BZHR)                                |
| **HDMI変換ケーブル** | Mini-HDMI to HDMI (1m〜)      | [Amazon (ケーブルタイプ推奨)](https://amzn.to/4ca25oP)                          |
| **超強力両面テープ** | 3M製など。フレーム固定用。    | [Amazon](https://www.amazon.co.jp/dp/B01B79Y6QO)                                |

## E. 必須・推奨工具 (Tools)

| 道具名               | 推奨品 / 型番              | 役割                       |
| :------------------- | :------------------------- | :------------------------- |
| **はんだごて**       | HAKKO FX-600               | 温度調節付。日本での定番。 |
| **ワイヤストリッパ** | **Vessel 3500E-2**         | シリコン線に最適。         |
| **テスター**         | Sanwa PM-3 / HIOKI 3244-60 | 電圧チェックに必須。       |
| **はんだ**           | 0.6〜0.8mm径 (鉛入り)      | 扱いやすさ重視。           |

---

### 💡 製作のアドバイス

- **ACアダプタの保護**: ヒューズは必ずACアダプタの直後（VCC側）に配置してください。
- **テスターの重要性**: はんだ付けが終わるたびに、VCCとGNDがショートしていないか「導通チェック」してください。
- **熱対策**: 144LED/mは熱を持ちやすいため、アルミプロファイルへの貼り付けを強く推奨します。

## F. 今後の改善・アップグレード予定 (Future Improvements)

| 項目                         | 目的               | 備考                                            |
| :--------------------------- | :----------------- | :---------------------------------------------- |
| **アルミプロファイル (U型)** | 放熱・高級感・固定 | LEDの寿命を延ばし、見た目が劇的に良くなります。 |
| **金切鋸 (Hacksaw)**         | アルミカット用     | プロファイルの長さを調整するために必要。        |
