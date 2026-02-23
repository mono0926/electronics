# 部品リスト (Bill of Materials) - Piano LED Visualizer

推奨リポジトリ [onlaj/Piano-LED-Visualizer](https://github.com/onlaj/Piano-LED-Visualizer) に基づいた、日本で調達可能な主な部品リストです。

## 1. コア部品

| 部品名              | 推奨仕様                    | Amazon.co.jp (参考)                                             | AliExpress (安価)                                                                | 備考                                 |
| :------------------ | :-------------------------- | :-------------------------------------------------------------- | :------------------------------------------------------------------------------- | :----------------------------------- |
| **Microcontroller** | Raspberry Pi Zero 2 W (推奨) | [RPi Zero 2 W](https://www.amazon.co.jp/s?k=Raspberry+Pi+Zero)  | [Search](https://www.aliexpress.com/w/wholesale-Raspberry-Pi-Zero-2-W.html)      | 処理能力に余裕があり、描画がスムーズです |
| **LED Strip**       | WS2812B 144LEDs/m (黒基板)  | [BTF-LIGHTING](https://www.amazon.co.jp/s?k=WS2812B+144+leds)   | [BTF-LIGHTING Official](https://www.aliexpress.com/w/wholesale-WS2812B.html)     | 鍵盤全体で通常1m〜1.2m必要           |
| **Power Supply**    | 5V 10A ACアダプタ           | [5V 10A アダプタ](https://www.amazon.co.jp/s?k=5V+10A+adapter)  | [5V 10A/15A Adapter](https://www.aliexpress.com/w/wholesale-5V-10A-PSU.html)     | 電流容量が不足するとLEDが明滅します  |
| **DC Jack**         | 5.5x2.1mm メス              | [DCジャック 変換](https://www.amazon.co.jp/s?k=DC+Jack+Adapter) | [DC Power Socket](https://www.aliexpress.com/w/wholesale-DC-5.5x2.1-Female.html) | ネジ式端子付きが初心者にはおすすめ   |
| **Level Shifter**   | 74AHCT125                   | [レベルシフタ](https://www.amazon.co.jp/dp/B07RWC9C5C)          | [74AHCT125 lot](https://www.aliexpress.com/w/wholesale-74AHCT125.html)           | 3.3V信号を5Vに昇圧してチラつきを防止 |
| **LCD Display**     | Waveshare 1.44inch (ST7735) | [1.44inch LCD](https://www.amazon.co.jp/dp/B07S8P8Y5C)          | [1.44 TFT LCD](https://www.aliexpress.com/w/wholesale-1.44-ST7735.html)          | IPアドレス等の確認に非常に便利       |

## 2. 電子工作用消耗品（徹底網羅）

これらは AliExpress でまとめ買いしておくと、今後のプロジェクトでも役立ちます。

| 部品名               | 推奨仕様 / サイズ          | AliExpress (参考検索)                                                        | 役割                                    |
| :------------------- | :------------------------- | :--------------------------------------------------------------------------- | :-------------------------------------- |
| **Silicon Wire**     | 18AWG (電源用)             | [18AWG Silicon Wire](https://www.aliexpress.com/w/wholesale-18AWG-wire.html) | 5V 10Aの大電流を安全に流すため          |
| **Silicon Wire**     | 24~26AWG (信号用)          | [24AWG Silicon Wire](https://www.aliexpress.com/w/wholesale-24AWG-wire.html) | ラズパイ本体との信号線に使用            |
| **Heat Shrink Tube** | 2mm, 4mm, 6mm (セット品)   | [Heat Shrink Kit](https://www.aliexpress.com/w/wholesale-Heat-Shrink.html)   | はんだ付け箇所の絶縁保護                |
| **Connectors**       | JST-SM 3-pin (オス/メス)   | [JST SM 3pin](https://www.aliexpress.com/w/wholesale-JST-SM-3pin.html)       | LEDストリップとコントローラを分離可能に |
| **Capacitor**        | 1000μF 6.3V~ (電解)        | [1000uF Capacitor](https://www.aliexpress.com/w/wholesale-1000uF-Cap.html)   | 電源投入時のLED保護（突入電流対策）     |
| **Resistor**         | 330Ω - 470Ω                | [Resistor Pack](https://www.aliexpress.com/w/wholesale-resistor-metal.html)  | データラインのノイズ・反射防止          |
| **Solder**           | 錫鉛はんだ または 鉛フリー | [Solder Wire](https://www.aliexpress.com/w/wholesale-Solder.html)            | 基板や線の固定（高密度なものは細めを）  |

## 3. アクセサリ・周辺機器

- **MicroSD Card**: 16GB / 32GB Class 10（信頼性の高い SanDisk 等を推奨）
- **USB OTG Hub**: Micro USB (オス) to USB-A (メス)（電子ピアノのMIDI出力と接続用）
- **Case / Mounting**: 3Dプリンター（Bambu Lab P2S）で自作、または適切な汎用ケース

---

### チップ選びと防水性能 (IP等級)

LEDストリップを選ぶ際、`IP30` や `IP65` といった表記があります。これは防塵・防水性能を示す数値です。

| 等級     | 状態       | ピアノビジュアライザーへの適性                                                  |
| :------- | :--------- | :------------------------------------------------------------------------------ |
| **IP30** | **非防水** | **◎ 最適**。最も薄く、放熱性に優れ、ハンダ付け等の加工も容易です。              |
| **IP65** | **防滴**   | **△**。シリコンコーティングの分だけ厚みが増し、経年で変色する可能性があります。 |
| **IP67** | **防水**   | **×**。チューブ入りで太く重いため、鍵盤への設置には不向きです。                 |

ピアノは室内で使用するため、最も薄くて扱いやすい **IP30**（Non-waterproof）を強く推奨します。

### 調達のヒント

> [!TIP]
> **コスト重視なら AliExpress**:
> LEDストリップ（144LEDs/m, IP30）やレベルシフタ、電線類はアリエクだと数分の一の価格で揃います。ただし到着に1〜2週間かかるため、急ぎの部品（ラズパイ本体やSDカード）だけ Amazon で買う「ハイブリッド調達」が mono さんのようなプロには合理的です。
---

### Raspberry Pi Zero W vs. Zero 2 W の比較

ピアノビジュアライザーにおける選択基準は以下の通りです。

| 項目 | Raspberry Pi Zero W | Raspberry Pi Zero 2 W |
| :--- | :--- | :--- |
| **CPU** | 1コア 1GHz (ARM11) | **4コア 1GHz (Cortex-A53)** |
| **性能** | 基本的な動作には十分 | **約5倍高速 (マルチコア)** |
| **メリット** | 安価、低消費電力 | **描画の遅延（レイテンシ）が最小限** |
| **デメリット** | 複雑なエフェクトで処理落ちの可能性 | 消費電力がわずかに高い (約3W) |

**結論:**
このプロジェクトでは、リアルタイムのMIDI処理、LED制御、および外部ディスプレイ（LCD）の同時使用を想定しているため、**Raspberry Pi Zero 2 W** を強く推奨します。特に和音の高速打鍵時や、複雑なアニメーション（Pulseモード等）において、Zero 2 Wの方が圧倒的にスムーズな体験が得られます。

---

### 「W」と「WH」の違い（GPIOヘッダー）

Raspberry Pi Zero シリーズの型番末尾には、以下のような意味があります。

- **W (Wireless)**: Wi-Fi と Bluetooth を搭載。
- **WH (Wireless Header)**: **GPIOピンヘッダーが実装済み**。
- **2 W**: 第2世代の Wireless モデル（ピンヘッダーは未実装が一般的）。

> [!TIP]
> **はんだ付けの手間を減らすなら**:
> レベルシフタやLCDとの配線が必要なため、GPIOピンが必要です。自身のスキルや道具に合わせて選びましょう。
> - **はんだ付けが得意**: 「W」または「2 W」を購入し、自分でピンヘッダーを立てる。
> - **楽をしたい**: 「WH」または「2 W with Header」として販売されているヘッダー付きモデルを探す。

---

### 高品質な仕上げのための組立ヒント

「高品質」の定義により、おすすめの構成が変わります。

#### 1. メンテナンス性と確実性（ヘッダーあり × コネクタ）
工場はんだ済みの **WH** 等を使用し、配線側に **JST-SM コネクタ** や **QIコネクタ** を圧着して接続する方法です。
- **メリット**: 万が一ラズパイが故障しても簡単に交換でき、接触不良も起きにくい。見た目も「製品」に近くなります。
- **デメリット**: ピンヘッダーとコネクタの分だけ、ケースに厚み（高さ）が必要になります。

#### 2. コンパクトさと美しさ（ヘッダーなし × 直接はんだ付け）
**W** または **2 W** を使用し、基板の穴（スルーホール）にシリコンワイヤーを直接はんだ付けする方法です。
- **メリット**: ヘッダーがない分、非常に薄く（数mm単位で）仕上げられます。3Dプリンターで超小型ケースを作る場合に有利です。
- **デメリット**: 交換や修理が困難で、はんだ付けが甘いと振動で外れるリスクがあります。

> [!IMPORTANT]
> **monoさんへの推奨**:
> 3Dプリンター（Bambu Lab P2S）をお持ちなので、**「1. メンテナンス性」重視**で少し余裕のあるケースを設計するのが、最終的なビルドクオリティと安心感が最も高くなると思われます。
