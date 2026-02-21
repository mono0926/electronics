# 部品リスト (Bill of Materials) - Piano LED Visualizer

推奨リポジトリ [onlaj/Piano-LED-Visualizer](https://github.com/onlaj/Piano-LED-Visualizer) に基づいた、日本で調達可能な主な部品リストです。

## 1. コア部品 (必須)

| 部品名              | 推奨仕様                         | Amazon(参考)                                                                                                                | 備考                            |
| :------------------ | :------------------------------- | :-------------------------------------------------------------------------------------------------------------------------- | :------------------------------ |
| **Microcontroller** | Raspberry Pi Zero WH             | [Amazon検索結果](https://www.amazon.co.jp/s?k=Raspberry+Pi+Zero+WH)                                                         | ヘッダーピン実装済みが楽です    |
| **LED Strip**       | WS2812B 144LEDs/m (黒基板推奨)   | [BTF-LIGHTING WS2812B](https://www.amazon.co.jp/s?k=WS2812B+144+leds)                                                       | 鍵盤幅に合わせるため144/mを推奨 |
| **Power Supply**    | 5V 10A ACアダプタ                | [5V 10A ACアダプタ](https://www.amazon.co.jp/s?k=5V+10A+%E3%82%A2%E3%83%80%E3%83%97%E3%82%BF)                               | 電流容量に余裕を持つ            |
| **DC Jack**         | 5.5x2.1mm または 2.5mm           | [DCジャック 変換](https://www.amazon.co.jp/s?k=DC%E3%82%B8%E3%83%83%E3%82%AF+%E3%82%BF%E3%83%BC%E3%83%9F%E3%83%8A%E3%83%AB) | ネジ式端子付きが配線しやすい    |
| **Capacitor**       | 1000μF 6.3V以上 (電解コンデンサ) |                                                                                                                             | 平滑用、LED保護                 |
| **Resistor**        | 330Ω - 470Ω                      |                                                                                                                             | データライン保護                |

## 2. 接続・アクセサリ

| 部品名           | 仕様                  | 備考                       |
| :--------------- | :-------------------- | :------------------------- |
| **MicroSD Card** | 16GB / 32GB Class 10  | OSイメージ書き込み用       |
| **USB OTG Hub**  | Micro USB to USB-A    | ピアノと接続するために必要 |
| **Jumper Wires** | メス-メス / オス-メス | ラズパイとLEDの接続用      |

## 3. オプション (あれば便利)

| 部品名            | 仕様                   | 目的                                |
| :---------------- | :--------------------- | :---------------------------------- |
| **LCD Display**   | Waveshare 1.44inch LCD | ステータス（IPアドレス等）表示用    |
| **Level Shifter** | 74AHCT125              | 3.3V(ラズパイ)を5V(LED)に確実に変換 |
