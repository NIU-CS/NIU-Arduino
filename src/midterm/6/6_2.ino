const byte digits[10] = {
    // 0-9 的顯示模式，針對共陰極顯示器
    B00111111,  // 0
    B00000110,  // 1
    B01011011,  // 2
    B01001111,  // 3
    B01100110,  // 4
    B01101101,  // 5
    B01111101,  // 6
    B00000111,  // 7
    B01111111,  // 8
    B01101111   // 9
};

int pins[] = {2, 3, 4, 5, 6, 7, 8};  // A-G 段顯示器的腳位

void setup() {
    for (int i = 0; i < 7; i++) {
        pinMode(pins[i], OUTPUT);  // 設定 A-G 段顯示器的腳位為輸出
    }
    Serial.begin(9600);  // 設置硬體串列通訊速率
}

void loop() {
    if (Serial.available()) {
        int value = Serial.read();  // 接收來自左側 Arduino 的數字

        // 使用 `digits` 陣列顯示對應數字
        if (value >= 0 && value <= 9) {  // 確保接收到的數字在 0 到 9 範圍內
            byte segments = digits[value];
            for (int i = 0; i < 7; i++) {
                digitalWrite(pins[i], bitRead(segments, i));  // 將控制位元顛倒
            }
        }
    }
}
