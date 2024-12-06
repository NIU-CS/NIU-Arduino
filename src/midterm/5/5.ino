const byte digits[4] = {
    // 只需要顯示 0 到 3 的數字
    B11000000,  // 0
    B11111001,  // 1
    B10100100,  // 2
    B10110000   // 3
};

int pins[] = {0, 1, 2, 3, 4, 5, 6};  // A-G 段顯示器的腳位
int switches[] = {9, 8};             // 開關 1 和 開關 2 的腳位

void setup() {
    for (int i = 0; i < 7; i++) {
        pinMode(pins[i], OUTPUT);  // 設定 A-G 段顯示器的腳位為輸出
    }
    for (int i = 0; i < 2; i++) {
        pinMode(switches[i],
                INPUT_PULLUP);  // 設定開關為輸入，並啟用內建上拉電阻
    }
}

void loop() {
    int value = 0;

    // 根據開關狀態計算數字值
    for (int i = 0; i < 2; i++) {
        if (digitalRead(switches[i]) == HIGH) {
            value += (1 << i);  // 根據開關的位元值累加計算結果
        }
    }

    // 使用 `digits` 陣列顯示對應數字
    byte segments = digits[value];
    for (int i = 0; i < 7; i++) {
        digitalWrite(pins[i], bitRead(segments, i));  // 根據對應位元設定段狀態
    }
}
