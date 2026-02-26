# Piano LED Visualizer ドキュメント・インデックス (Document Map)

このページは、プロジェクト内に存在するすべてのドキュメントへの道しるべです。
作業のフェーズや目的に合わせて、必要なドキュメントを参照してください。

---

## 🚀 まず最初に読むべきガイド

- [**プロジェクト README**](../README.md): プロジェクトの概要とディレクトリ構造。
- [**ビギナーズ・スタートガイド**](getting_started_guide.md): パーツ購入から完成までのロードマップと基本手順。初心者はここから！

---

## 🛠 ハードウェア・電子工作 (Hardware & Build)

部品の選定から組み立てまでの一連のガイドです。

### 全体計画と部品

- [**徹底網羅：部品・工具リスト (BOM)**](../hardware/bom.md)
- [**基板構成の比較: スタッキング vs 横並び**](../hardware/assembly_options.md): 熱対策に優れる「横並び（案B）」を標準推奨しています。
- [**配線ガイド (Wiring Guide)**](../hardware/wiring.md): ラズパイ、レベルシフタ、LEDテープの全体配線図です。

### 組み立てステップ（フェーズ2）

1. [**LEDテープの準備と加工**](hw_step2_1_led_prep.md)
2. [**コントローラー（ラズパイ・レベルシフタ）の配線**](hw_step2_2_controller.md) (※横並び推奨)
3. [**電源システムと安全回路**](hw_step2_3_power_safety.md)
4. [**ピアノへの取り付けと最終接続**](hw_step2_4_final_assembly.md)

### ケース設計・3Dプリント

- [**筐体（ケース）設計検討**](../hardware/case_design.md): 熱対策のために横並びケースを採用した経緯。
- [**3Dプリント筐体・専用ケース設計ガイド**](../hardware/case_3d_modeling_guide.md): Bambu Lab P2S で作る自作ケースの手順。
- [**3Dプリントと設置ガイド**](../hardware/printing_and_mounting.md): 全般的なP2S出力設定とヒント。
- [**プロトタイピング中の基板保護ガイド**](../hardware/temporary_protection.md): 制作中（むき出し状態）のショート防止バンパーについて。

### アレンジ・安全性

- [**ピアノ用ハイブリッドLEDレール制作ガイド**](../hardware/housing_build_guide.md): アルミとシリコンチューブを組み合わせた剛性の高いレールの作り方。
- [**安全のための「ヒューズ」講座**](../hardware/safety_guide.md)
- [**設置・固定ガイド**](mounting_and_installation_guide.md): ピアノへの物理的な取り付け方。

---

## 💻 ソフトウェア・設定 (Software & Configuration)

OSやプログラムの導入、設定に関するガイドです。

- [**ソフトウェアセットアップ・設定ガイド**](../setup_guide.md): ラズパイOSのインストール、Web UIの設定方法、トラブルシューティングから発展的なアニメーションモードの解説まで。
- [**設定・活用ガイド**](configuration_and_usage_guide.md): Synthesia等の外部ソフト連携やピアノのマッピング。
- [**トラブルシューティング & FAQ**](faq_and_troubleshooting.md): 光らない、繋がらない、色が変などの問題解決集。

---

## 🧠 設計資料・アドバンス (Advanced Concepts)

システムの仕組みや技術的な背景を知りたいエンジニア向け資料です。

- [**技術的解説・要件定義**](requirements.md): なぜこの部品構成が必要なのか（電力注入や電圧降下の解説）。
- [**内部ロジック解説**](../logic_breakdown.md): PythonコードにおけるLED位置計算やMIDIイベント処理の中身について。

---

## 📚 本家ドキュメント (`external` ディレクトリ)

基本的な組み立てと設定が終わった後に読む「**機能リファレンス**」です。

- [**ソフトウェアの全機能・エフェクト事典**](https://github.com/mono0926/Piano-LED-Visualizer/blob/ja/Docs/features.md): 様々な光り方（ベロシティ・レインボー等）や、内蔵の録音・自動再生・学習モードの図解。**完成後、一番最初に読むべきマニュアル**です。
- [**外部アプリ連携・発展的な使い方**](https://github.com/mono0926/Piano-LED-Visualizer/blob/ja/Docs/external_devices.md): スマホやタブレット上のピアノアプリと連動させるための具体的な機器構成パターン（有線・ネットワーク・Bluetooth等）。
- [**本家独自の改造アイデアとその他**](https://github.com/mono0926/Piano-LED-Visualizer/blob/ja/Docs/cover_detection.md): 鍵盤カバー開閉検知ギミックなどのニッチな機能解説。
