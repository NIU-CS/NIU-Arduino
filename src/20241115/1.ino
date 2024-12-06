// 引用 Keypad library
#include <Keypad.h>

// 4x4 Keypad
const byte ROWS = 4;  // 4 Rows
const byte COLS = 4;  // 4 Columns

// 定義 Keypad 的按鍵 (從左到右 從上到下)
char keys[ROWS][COLS] = {
    {'1', '2', '3', 'A'},  // 第一列
    {'4', '5', '6', 'B'},  // 第二列
    {'7', '8', '9', 'C'},  // 第三列
    {'*', '0', '#', 'D'}   // 第四列
};

// 定義 Keypad 連到 Arduino 的接腳
// 由列跟欄來定位按下的地方
// 在由keys去對應出相對應的值
// 連到 Keypad 的 4 個 Rows: Row0, Row1, Row2, Row3
byte rowPins[ROWS] = {5, 4, 3, 2};
// 連到 Keypad 的 4 個 Columns: Column0, Column1, Column2, Column3
byte colPins[COLS] = {9, 8, 7, 6};

// 建立 Keypad 物件
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup() { Serial.begin(9600); }

void loop() {
    char key = keypad.getKey();  // 讀取 Keypad 的輸入

    if (key != NO_KEY) {
        Serial.println(key);
    }
}
