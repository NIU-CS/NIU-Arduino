
// 定義七段顯示器的接腳對應
const int segPins[] = {2, 3, 4, 5, 6, 7, 8}; // 接腳對應 A, B, C, D, E, F, G
const int buttonUp = 9;   // 增加按鈕接腳
const int buttonDown = 10; // 減少按鈕接腳

int currentValue = 0;  // 當前顯示數值

// 七段顯示器對應數字 0-9 的狀態
const byte digits[10] = {
    B00111111, // 0
    B00000110, // 1
    B01011011, // 2
    B01001111, // 3
    B01100110, // 4
    B01101101, // 5
    B01111101, // 6
    B00000111, // 7
    B01111111, // 8
    B01101111  // 9
};

void setup() {
    for (int i = 0; i < 7; i++) {
        pinMode(segPins[i], OUTPUT);
    }
    pinMode(buttonUp, INPUT_PULLUP);
    pinMode(buttonDown, INPUT_PULLUP);
    displayDigit(currentValue);
}

void loop() {
    if (digitalRead(buttonUp) == LOW) {
        delay(200); // 防抖動
        currentValue = (currentValue + 1) % 10; // 遞增並保持在 0-9 範圍
        displayDigit(currentValue);
    }
    if (digitalRead(buttonDown) == LOW) {
        delay(200); // 防抖動
        currentValue = (currentValue - 1 + 10) % 10; // 遞減並保持在 0-9 範圍
        displayDigit(currentValue);
    }
}

// 顯示數位到七段顯示器
void displayDigit(int number) {
    byte segments = digits[number];
    for (int i = 0; i < 7; i++) {
        digitalWrite(segPins[i], (segments >> i) & 0x01);
    }
}
