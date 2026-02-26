# Piano LED Visualizer 🎹✨

電子ピアノの鍵盤が押された際に、その真上のLEDが光るシステムを構築するプロジェクトです。
本プロジェクトは、[onlaj/Piano-LED-Visualizer](https://github.com/onlaj/Piano-LED-Visualizer) の構成に準拠して制作を進めています。

## ディレクトリ構造

- `/docs`: 要件定義、設計書、配線図
- `/firmware`: マイコン（Arduino等）用ソースコード
- `/hardware`: 部品表 (BOM)、回路図
- `/models`: 3Dプリンター用モデルデータ
- `/external`: [onlaj/Piano-LED-Visualizer](https://github.com/onlaj/Piano-LED-Visualizer) の日本語訳済サブモジュール

## サブモジュールの利用

本プロジェクトでは、オリジナルのリポジトリを [mono0926/Piano-LED-Visualizer](https://github.com/mono0926/Piano-LED-Visualizer) にフォークし、`ja` ブランチで日本語訳を管理しています。

最新のオリジナルドキュメント（日本語訳）は `/external/README.md` を参照してください。

### 更新ワークフロー

オリジナルの更新を取り込む場合は、以下の手順で行います：

1. `external` ディレクトリで `upstream` (onlaj版) から `main` にプル
2. `ja` ブランチに切り替え、`main` をマージまたはリベース
3. 日本語訳を適宜更新してプッシュ

---

## 🏁 はじめかた

プロジェクトを開始するための手厚いガイドを用意しました。部品が届く前の準備から、完成後の調整までをカバーしています。

- [**ビギナーズ・スタートガイド**](docs/getting_started_guide.md) 👈 まずはこちら！

### ドキュメント全集

- [**ドキュメント・インデックス (Document Map)**](docs/index.md)
  - すべてのハードウェア・ソフトウェアのガイドや設計資料を一覧できます。作業中に行き詰まったり、より詳しい情報が必要な場合はこちらをご参照ください。

---

## 現在のステータス

- プロジェクト初期構築中
- 要件定義（MIDI連動、WS2812B使用）の整理完了
- オリジナルドキュメントのサブモジュール化と日本語化（`ja` ブランチ）完了
- 初心者向けスタートガイド作成完了
