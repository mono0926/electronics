/*
 * ============================================================
 * スピードキューブ・タイマー
 * ============================================================
 *
 * 概要:
 *   SpeedStacks G5 Stackmat 風のルービックキューブ用タイマー。
 *   両手をタッチパッドに置いて準備 → 離してスタート → 戻してストップ。
 *
 * ハードウェア:
 *   - Arduino Nano (ATmega328P)
 *   - OLED 1.3" I2C SSD1306 (128x64)
 *   - TTP223 タッチセンサー ×2 (左手・右手)
 *   - Cherry MX 互換キーボードスイッチ ×1 (リセット)
 *   - アクティブブザー ×1
 *   - トグルスイッチ (電源)
 *
 * 配線:
 *   D2 ← タッチセンサー(左) SIG    (タッチ時 HIGH)
 *   D3 ← タッチセンサー(右) SIG    (タッチ時 HIGH)
 *   D4 ← リセットスイッチ          (INPUT_PULLUP, 押下時 LOW)
 *   D8 → アクティブブザー
 *   A4 → OLED SDA
 *   A5 → OLED SCL
 *
 * ライブラリ (Arduino IDE で事前にインストール):
 *   - Adafruit SSD1306: ツール → ライブラリの管理 → "Adafruit SSD1306" 検索
 *   - Adafruit GFX:     ツール → ライブラリの管理 → "Adafruit GFX" 検索
 *
 * 作者: mono & agy
 * ライセンス: MIT
 */

// ============================================================
//  ライブラリのインクルード
// ============================================================
// Wire: I2C通信用の標準ライブラリ。Arduino に最初から入っている。
//       OLED ディスプレイとの通信に使う。
#include <Wire.h>

// Adafruit_GFX: グラフィックス描画の基盤ライブラリ。
//               点・線・テキストなどの描画機能を提供する。
#include <Adafruit_GFX.h>

// Adafruit_SSD1306: SSD1306 OLED ドライバ。
//                   GFX の描画命令を OLED に送信する。
#include <Adafruit_SSD1306.h>

// EEPROM: 不揮発性メモリ。電源を切ってもデータが消えない。
//         自己ベストタイムの保存に使う。
#include <EEPROM.h>

// ============================================================
//  定数定義
// ============================================================

// --- ピン割り当て ---
// const は「この値は変わりません」という宣言。
// コンパイラが最適化してくれるため、#define より安全。
const int PIN_TOUCH_LEFT  = 2;   // 左手タッチセンサー (TTP223)
const int PIN_TOUCH_RIGHT = 3;   // 右手タッチセンサー (TTP223)
const int PIN_RESET       = 4;   // リセットボタン (キーボードスイッチ)
const int PIN_BUZZER      = 8;   // アクティブブザー

// --- OLED ディスプレイ設定 ---
const int SCREEN_WIDTH  = 128;   // OLEDの横ピクセル数
const int SCREEN_HEIGHT = 64;    // OLEDの縦ピクセル数
const int OLED_RESET    = -1;    // リセットピン (-1 = Arduinoのリセットを共有)
const int OLED_ADDRESS  = 0x3C;  // I2Cアドレス (SSD1306の標準)

// --- タイマー設定 ---
// millis() は Arduino 起動からのミリ秒を返す関数（unsigned long型）。
// unsigned long は 0〜4,294,967,295 まで。約49日分。
const unsigned long READY_HOLD_TIME   = 500;   // SET状態に移行するまでのホールド時間 (ms)
const unsigned long DEBOUNCE_DELAY    = 50;    // リセットボタンのデバウンス時間 (ms)
const unsigned long DISPLAY_INTERVAL  = 33;    // 画面更新間隔 (ms) ≒ 30fps
const unsigned long BEEP_DURATION     = 100;   // ビープ音の長さ (ms)

// --- 記録管理 ---
const int MAX_SOLVES        = 100;  // 保持する最大記録数
const int EEPROM_BEST_ADDR  = 0;    // EEPROMのベストタイム保存先アドレス

// ============================================================
//  状態マシン（ステートマシン）
// ============================================================
// タイマーの「今の状態」を表す列挙型。
// 列挙型(enum)を使うと、数字の代わりに名前で状態を管理できるので読みやすい。
//
// 状態遷移図:
//
//                     ┌──[RST押下]──┐
//                     ↓             │
// [IDLE] ─(両手タッチ)→ [READY] ─(0.5秒ホールド)→ [SET]
//                                                    │
//                                              (両手リリース)
//                                                    ↓
// [IDLE] ←─(結果表示)── [STOPPED] ←─(両手タッチ)── [RUNNING]
//
enum State {
  STATE_IDLE,     // 待機中: 前回の結果を表示
  STATE_READY,    // 準備中: 両手がタッチされた (0になるがまだスタートしない)
  STATE_SET,      // セット: 0.5秒ホールド完了。離すとスタート
  STATE_RUNNING,  // 計測中: タイマーがカウントアップ中
  STATE_STOPPED   // 停止:   結果を表示中
};

// ============================================================
//  グローバル変数
// ============================================================

// --- OLED ディスプレイオブジェクト ---
// Adafruit_SSD1306 のコンストラクタに画面サイズとI2C設定を渡す。
// &Wire は I2C 通信オブジェクトのポインタ（アドレス）。
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// --- 状態管理 ---
State currentState = STATE_IDLE;    // 現在の状態

// --- タイマー変数 ---
unsigned long startTime = 0;        // タイマースタート時刻
unsigned long elapsedTime = 0;      // 経過時間 (ms)
unsigned long readyStartTime = 0;   // READY状態に入った時刻 (ホールド計測用)
unsigned long lastDisplayUpdate = 0; // 最後に画面を更新した時刻

// --- リセットボタンのデバウンス ---
int lastResetState = HIGH;          // 前回のボタン状態 (INPUT_PULLUP なので初期値は HIGH)
unsigned long lastResetDebounce = 0; // 最後にボタン状態が変わった時刻

// --- ブザー制御 ---
unsigned long beepStartTime = 0;    // ブザー鳴動開始時刻
bool beepActive = false;            // ブザーが鳴っているか

// --- 記録管理 ---
// solve = 1回のキューブ解き
unsigned long solves[MAX_SOLVES];    // 記録配列
int solveCount = 0;                 // 現在の記録数
int solveIndex = 0;                 // 次に書き込む位置 (リングバッファ)
unsigned long bestTime = 0;         // 自己ベストタイム (0 = 記録なし)

// ============================================================
//  セットアップ（電源ON時に1回だけ実行）
// ============================================================
void setup() {
  // --- ピンモード設定 ---
  // INPUT:        外部からの信号を読む
  // INPUT_PULLUP: 内蔵プルアップ抵抗を有効にして読む
  // OUTPUT:       外部に信号を出す
  pinMode(PIN_TOUCH_LEFT,  INPUT);        // TTP223 は自前でHIGH/LOWを出力するので普通のINPUT
  pinMode(PIN_TOUCH_RIGHT, INPUT);        // 同上
  pinMode(PIN_RESET,       INPUT_PULLUP); // 内蔵プルアップ: 押してない時=HIGH, 押した時=LOW
  pinMode(PIN_BUZZER,      OUTPUT);       // ブザーへ出力

  // ブザーを確実にOFFにする
  digitalWrite(PIN_BUZZER, LOW);

  // --- シリアル通信の初期化 (デバッグ用) ---
  // Arduino IDE の「シリアルモニタ」でデバッグメッセージが見える。
  // 9600 はボーレート（通信速度）。1秒あたり9600ビット。
  Serial.begin(9600);
  Serial.println(F("=== Cube Timer Starting ==="));
  // F() マクロ: 文字列をフラッシュメモリに置く。SRAMの節約になる。
  // Arduino Nano の SRAM は 2KB しかないので、文字列はフラッシュに置くのが定石。

  // --- OLED ディスプレイの初期化 ---
  // SSD1306_SWITCHCAPVCC: 内部のチャージポンプ回路で3.3Vから表示用電圧を生成
  // （外部に昇圧回路を用意しなくて良いので便利）
  if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDRESS)) {
    // 初期化失敗 = OLED が見つからない
    Serial.println(F("ERROR: OLED not found!"));
    // 無限ループで停止（表示なしでは使えないので）
    for (;;);
  }

  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE); // 単色OLEDなので WHITE = 点灯

  // --- EEPROM からベストタイムを読み込む ---
  // EEPROM.get() は指定アドレスからデータ構造体を読む。
  // unsigned long は 4バイトなので、アドレス0〜3の4バイトを読む。
  EEPROM.get(EEPROM_BEST_ADDR, bestTime);
  // 未初期化のEEPROMは全ビット1 (0xFFFFFFFF) なのでチェック
  if (bestTime == 0xFFFFFFFF) {
    bestTime = 0;  // 記録なし
  }

  // --- 起動画面の表示 ---
  drawSplashScreen();
  delay(1500); // 1.5秒表示

  // --- IDLE 画面表示 ---
  drawIdleScreen();
}

// ============================================================
//  メインループ（繰り返し実行）
// ============================================================
// Arduino のプログラムは setup() → loop() → loop() → ... と
// loop() が無限に繰り返される。1回のloop()は数マイクロ秒で終わるので、
// 体感的にはリアルタイムで動いているように見える。
void loop() {
  // --- 入力の読み取り ---
  bool leftTouch  = digitalRead(PIN_TOUCH_LEFT)  == HIGH; // TTP223: タッチ=HIGH
  bool rightTouch = digitalRead(PIN_TOUCH_RIGHT) == HIGH;
  bool bothTouched = leftTouch && rightTouch;               // 両手タッチ
  bool bothReleased = !leftTouch && !rightTouch;            // 両手リリース

  // --- リセットボタンのデバウンス処理 ---
  bool resetPressed = readResetButton();

  // --- ブザーの自動停止 ---
  updateBuzzer();

  // --- 状態マシンの更新 ---
  // switch文で「現在の状態」に応じた処理を実行する。
  // これが状態マシン（ステートマシン）の基本パターン。
  switch (currentState) {

    // ---- IDLE: 待機中 ----
    case STATE_IDLE:
      if (bothTouched) {
        // 両手がタッチされた → READY へ遷移
        currentState = STATE_READY;
        readyStartTime = millis(); // ホールド時間の計測開始
        elapsedTime = 0;
        drawReadyScreen();
        Serial.println(F("State: IDLE -> READY"));
      }
      break;

    // ---- READY: 準備中 (両手タッチして待機) ----
    case STATE_READY:
      if (!bothTouched) {
        // 両手が離れた → 0.5秒ホールドせずに離した → IDLE に戻る
        currentState = STATE_IDLE;
        drawIdleScreen();
        Serial.println(F("State: READY -> IDLE (released too early)"));
      } else if (millis() - readyStartTime >= READY_HOLD_TIME) {
        // 0.5秒以上ホールドした → SET へ遷移
        currentState = STATE_SET;
        beep(); // ビープ音で「準備完了」を通知
        drawSetScreen();
        Serial.println(F("State: READY -> SET"));
      }
      break;

    // ---- SET: セット完了 (離すとスタート) ----
    case STATE_SET:
      if (!bothTouched) {
        // 両手が離れた → タイマースタート!
        currentState = STATE_RUNNING;
        startTime = millis();
        Serial.println(F("State: SET -> RUNNING (Timer started!)"));
      }
      break;

    // ---- RUNNING: 計測中 ----
    case STATE_RUNNING:
      // 経過時間の更新
      elapsedTime = millis() - startTime;

      if (bothTouched) {
        // 両手がタッチされた → タイマーストップ!
        currentState = STATE_STOPPED;
        beep(); // ストップ音
        recordSolve(elapsedTime);
        drawStoppedScreen();
        Serial.print(F("State: RUNNING -> STOPPED (Time: "));
        Serial.print(formatTime(elapsedTime));
        Serial.println(F(")"));
      }

      // 画面更新 (約30fps)
      // 毎回のloop()で画面を書き換えると遅くなるので、間隔を空ける。
      if (millis() - lastDisplayUpdate >= DISPLAY_INTERVAL) {
        drawRunningScreen();
        lastDisplayUpdate = millis();
      }
      break;

    // ---- STOPPED: 結果表示中 ----
    case STATE_STOPPED:
      if (bothTouched) {
        // 次の計測を開始する準備
        currentState = STATE_READY;
        readyStartTime = millis();
        elapsedTime = 0;
        drawReadyScreen();
        Serial.println(F("State: STOPPED -> READY"));
      }
      break;
  }

  // --- リセット処理 (どの状態からでもリセット可能) ---
  if (resetPressed) {
    currentState = STATE_IDLE;
    elapsedTime = 0;
    drawIdleScreen();
    beep();
    Serial.println(F("RESET pressed"));
  }
}

// ============================================================
//  入力処理
// ============================================================

/**
 * リセットボタンの状態を読み取る（デバウンス付き）
 *
 * デバウンスとは:
 *   メカニカルスイッチは押した瞬間に接点がバウンド（跳ね返り）して、
 *   数ミリ秒の間に HIGH/LOW が激しく切り替わる（チャタリング）。
 *   これを1回の押下として正しく認識するための処理。
 *
 * @return true: ボタンが押された瞬間, false: それ以外
 */
bool readResetButton() {
  int reading = digitalRead(PIN_RESET);  // 現在のピン状態を読む

  // 状態が変わったら、デバウンスタイマーをリセット
  if (reading != lastResetState) {
    lastResetDebounce = millis();
  }
  lastResetState = reading;

  // デバウンス時間が経過 + ボタンが押されている (LOW = 押下)
  if ((millis() - lastResetDebounce > DEBOUNCE_DELAY) && reading == LOW) {
    // 一度処理したら再度反応しないように時刻をリセット
    lastResetDebounce = millis();
    return true;
  }

  return false;
}

// ============================================================
//  ブザー制御
// ============================================================

/**
 * ビープ音を鳴らす（ノンブロッキング）
 *
 * ブロッキング vs ノンブロッキング:
 *   delay(100) で 100ms 待つ方法（ブロッキング）だと、
 *   その間タッチセンサーの入力を読めなくなる。
 *   代わりに「鳴らし始めた時刻」を記録して、
 *   毎 loop() で経過時間をチェックする（ノンブロッキング）。
 */
void beep() {
  digitalWrite(PIN_BUZZER, HIGH);  // ブザーON
  beepActive = true;
  beepStartTime = millis();
}

/**
 * ブザーの自動停止チェック
 * loop() 内で毎回呼ばれる。
 */
void updateBuzzer() {
  if (beepActive && (millis() - beepStartTime >= BEEP_DURATION)) {
    digitalWrite(PIN_BUZZER, LOW);  // ブザーOFF
    beepActive = false;
  }
}

// ============================================================
//  記録管理
// ============================================================

/**
 * 新しい solve タイムを記録する
 *
 * リングバッファ方式:
 *   配列の末尾まで来たら先頭に戻って古い記録を上書きする。
 *   これにより、固定サイズの配列で「直近N件」を管理できる。
 *
 *   例: MAX_SOLVES=5, 7回目の記録
 *   [rec5, rec6, rec7, rec4, rec5]
 *              ↑ solveIndex (次に書く位置)
 */
void recordSolve(unsigned long time) {
  solves[solveIndex] = time;
  solveIndex = (solveIndex + 1) % MAX_SOLVES;  // % はモジュロ（剰余演算子）。100で割った余り。
  if (solveCount < MAX_SOLVES) {
    solveCount++;
  }

  // ベストタイム更新チェック
  if (bestTime == 0 || time < bestTime) {
    bestTime = time;
    // EEPROM に保存（電源を切っても消えない）
    // EEPROM.put() は値が変わった時だけ書き込む（摩耗防止）。
    // EEPROM の書き込み回数は約10万回が寿命。毎回書くと壊れるので注意。
    EEPROM.put(EEPROM_BEST_ADDR, bestTime);
    Serial.println(F("New best time!"));
  }
}

/**
 * Average of N を計算する（競技ルール準拠）
 *
 * 競技ルール:
 *   Avg of 5: 5回のうち最速・最遅を除いた3回の平均
 *   Avg of 12: 12回のうち最速・最遅を除いた10回の平均
 *
 * @param n  平均を取る回数 (5 or 12)
 * @return   平均タイム (ms)。記録が足りない場合は 0。
 */
unsigned long calcAvgOfN(int n) {
  if (solveCount < n) return 0;  // 記録不足

  // 直近 n 件を取得
  unsigned long times[12];  // 最大12件
  for (int i = 0; i < n; i++) {
    // リングバッファから新しい順に取り出す
    int idx = (solveIndex - 1 - i + MAX_SOLVES) % MAX_SOLVES;
    times[i] = solves[idx];
  }

  // 最速と最遅を見つける
  unsigned long fastest = times[0];
  unsigned long slowest = times[0];
  for (int i = 1; i < n; i++) {
    if (times[i] < fastest) fastest = times[i];
    if (times[i] > slowest) slowest = times[i];
  }

  // 最速・最遅を除いた合計を計算
  unsigned long sum = 0;
  for (int i = 0; i < n; i++) {
    sum += times[i];
  }
  sum -= fastest;
  sum -= slowest;

  return sum / (n - 2);  // 整数除算（小数点以下は切り捨て）
}

// ============================================================
//  時間フォーマット
// ============================================================

/**
 * ミリ秒を "SS.sss" 形式の文字列に変換する
 *
 * 例: 12345ms → "12.345"
 *     9050ms  → " 9.050"  (先頭スペースで桁揃え)
 *
 * String クラスは動的メモリ確保をするので、
 * 組み込み環境では char 配列の方がメモリ効率が良い。
 * ただし今回は可読性を優先して String を使う。
 */
String formatTime(unsigned long ms) {
  unsigned long secs = ms / 1000;          // 秒の部分
  unsigned long milliPart = ms % 1000;     // ミリ秒の部分

  // 分が付く場合
  if (secs >= 60) {
    unsigned long mins = secs / 60;
    secs = secs % 60;
    char buf[12];
    // sprintf: C言語の書式付き文字列生成。%02lu = 2桁ゼロ埋めの unsigned long。
    sprintf(buf, "%lu:%02lu.%03lu", mins, secs, milliPart);
    return String(buf);
  }

  char buf[10];
  sprintf(buf, "%2lu.%03lu", secs, milliPart);
  return String(buf);
}

// ============================================================
//  画面描画
// ============================================================
// OLED の描画は以下の手順:
//   1. display.clearDisplay()  — バッファをクリア
//   2. display.setTextSize() 等で設定
//   3. display.setCursor() で描画位置を指定
//   4. display.print() でバッファに書き込む
//   5. display.display()       — バッファの内容を実際にOLEDに転送
//
// ※ バッファ方式なので、display() を呼ぶまで画面に反映されない。
//    一度に全画面を更新するので、ちらつきが少ない。

/**
 * 起動画面（スプラッシュスクリーン）
 */
void drawSplashScreen() {
  display.clearDisplay();

  display.setTextSize(1);
  display.setCursor(20, 10);
  display.print(F("CUBE TIMER"));

  display.setCursor(35, 30);
  display.print(F("v1.0"));

  // 小さなキューブのアイコン的な四角を描画
  display.drawRect(55, 45, 18, 18, SSD1306_WHITE);
  display.drawLine(55 + 6, 45, 55 + 6, 45 + 18, SSD1306_WHITE);
  display.drawLine(55 + 12, 45, 55 + 12, 45 + 18, SSD1306_WHITE);
  display.drawLine(55, 45 + 6, 55 + 18, 45 + 6, SSD1306_WHITE);
  display.drawLine(55, 45 + 12, 55 + 18, 45 + 12, SSD1306_WHITE);

  display.display();
}

/**
 * IDLE画面: 前回の結果 + Best + Avg
 */
void drawIdleScreen() {
  display.clearDisplay();

  // タイトル
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.print(F("CUBE TIMER"));

  // 前回のタイム (大きく)
  display.setTextSize(2);
  display.setCursor(10, 16);
  if (elapsedTime > 0) {
    display.print(formatTime(elapsedTime));
  } else {
    display.print(F("Ready"));
  }

  // 統計情報
  display.setTextSize(1);

  // Best
  display.setCursor(0, 38);
  display.print(F("Best: "));
  if (bestTime > 0) {
    display.print(formatTime(bestTime));
  } else {
    display.print(F("---"));
  }

  // Avg of 5
  display.setCursor(0, 48);
  display.print(F("Ao5:  "));
  unsigned long ao5 = calcAvgOfN(5);
  if (ao5 > 0) {
    display.print(formatTime(ao5));
  } else {
    display.print(F("---"));
  }

  // Avg of 12
  display.setCursor(0, 56);
  display.print(F("Ao12: "));
  unsigned long ao12 = calcAvgOfN(12);
  if (ao12 > 0) {
    display.print(formatTime(ao12));
  } else {
    display.print(F("---"));
  }

  display.display();
}

/**
 * READY画面: 0.000 表示 (まだスタートしない)
 */
void drawReadyScreen() {
  display.clearDisplay();

  display.setTextSize(1);
  display.setCursor(0, 0);
  display.print(F("Hold..."));

  display.setTextSize(3);
  display.setCursor(10, 22);
  display.print(F("0.000"));

  display.display();
}

/**
 * SET画面: 0.000 表示 + 「離すとスタート」
 */
void drawSetScreen() {
  display.clearDisplay();

  display.setTextSize(1);
  display.setCursor(0, 0);
  display.print(F(">> GO! <<"));

  display.setTextSize(3);
  display.setCursor(10, 22);
  display.print(F("0.000"));

  display.setTextSize(1);
  display.setCursor(15, 56);
  display.print(F("Release to start"));

  display.display();
}

/**
 * RUNNING画面: カウントアップ中のタイム表示
 */
void drawRunningScreen() {
  display.clearDisplay();

  // 経過時間を大きく表示
  display.setTextSize(3);
  display.setCursor(2, 20);
  display.print(formatTime(elapsedTime));

  display.display();
}

/**
 * STOPPED画面: 最終タイム + 統計情報
 */
void drawStoppedScreen() {
  display.clearDisplay();

  // 最終タイム (大きく)
  display.setTextSize(2);
  display.setCursor(10, 5);
  display.print(formatTime(elapsedTime));

  // ベスト更新の場合
  if (elapsedTime == bestTime) {
    display.setTextSize(1);
    display.setCursor(85, 0);
    display.print(F("NEW!"));
  }

  // 区切り線
  display.drawLine(0, 24, 128, 24, SSD1306_WHITE);

  // 統計情報
  display.setTextSize(1);

  display.setCursor(0, 28);
  display.print(F("Best: "));
  display.print(formatTime(bestTime));

  display.setCursor(0, 40);
  display.print(F("Ao5:  "));
  unsigned long ao5 = calcAvgOfN(5);
  if (ao5 > 0) {
    display.print(formatTime(ao5));
  } else {
    display.print(F("---"));
  }

  display.setCursor(0, 50);
  display.print(F("Ao12: "));
  unsigned long ao12 = calcAvgOfN(12);
  if (ao12 > 0) {
    display.print(formatTime(ao12));
  } else {
    display.print(F("---"));
  }

  // solve回数
  display.setCursor(80, 56);
  display.print(F("#"));
  display.print(solveCount);

  display.display();
}
