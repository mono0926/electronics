# プロジェクト要件定義: Piano LED Visualizer

## 1. 目的

電子ピアノの演奏に合わせて、鍵盤の真上のLEDをリアルタイムに点灯させ、演奏の視覚化を楽しむ。

## 2. システム構成

### ハードウェア

- **マイコン (Microcontroller)**:
  - Arduino (Leonardo, Pro Micro) [推奨: USB MIDIが扱いやすいため]
  - または Raspberry Pi Zero
- **LEDテープ**:
  - WS2812B (アドレッサブルRGB LED)
- **電源**:
  - 5V 外付け電源 (ACアダプタ等)
  - ※ 多数のLEDを点灯させるため、マイコンからの給電ではなく外部電源が推奨される

### ソフトウェア・通信

- **入力**: ピアノの MIDI OUT または USB MIDI
- **制御ロジック**: MIDIノート番号を受け取り、対応するLEDのインデックスを点灯させる

## 3. 機能要件

- 鍵盤が押されたら対応する位置のLEDが点灯する
- 鍵盤を離したらLEDが消灯する
- 低レイテンシでの反応

## 4. 参考リソース

- Piano LED Visualizer (GitHub)
- MIDI2Neopixel
