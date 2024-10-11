// 定義引腳
int potPin1 = A0;                           // 第一個電位器接在 A0
int potPin2 = A1;                           // 第二個電位器接在 A1
int segmentPins[] = {2, 3, 4, 5, 6, 7, 8};  // 七段顯示器的段位控制腳

// 16 進制數字到七段顯示器的對應表
byte segmentHex[] = {
    B00111111,  // 0
    B00000110,  // 1
    B01011011,  // 2
    B01001111,  // 3
    B01100110,  // 4
    B01101101,  // 5
    B01111101,  // 6
    B00000111,  // 7
    B01111111,  // 8
    B01101111,  // 9
    B01110111,  // A
    B01111100,  // B
    B00111001,  // C
    B01011110,  // D
    B01111001,  // E
    B01110001   // F
};

void setup() {
    // 設定所有七段顯示器的腳為輸出
    for (int i = 0; i < 7; i++) {
        pinMode(segmentPins[i], OUTPUT);
    }
}

void loop() {
    // 讀取電位器的數值
    int val1 = analogRead(potPin1);
    int val2 = analogRead(potPin2);

    // 將電位器的值劃分為 8 個區段
    int val1Mapped = map(val1, 0, 1023, 0, 7);  // 將電位器 1 的值劃分到 0 到 7
    int val2Mapped = map(val2, 0, 1023, 0, 7);  // 將電位器 2 的值劃分到 0 到 7

    // 將兩個電位器的數值相加
    int sum = val1Mapped + val2Mapped;

    // 取16進制數值
    if (sum > 15) {
        sum = 15;  // 限制最大值為 15 (F)
    }

    // 顯示數值到七段顯示器
    displayNumber(sum);

    delay(200);  // 延遲，避免讀取過於頻繁
}

void displayNumber(int num) {
    byte segments = segmentHex[num];  // 取得對應數字的七段顯示器編碼

    // 根據編碼控制顯示器的段位
    for (int i = 0; i < 7; i++) {
        digitalWrite(segmentPins[i], (segments >> i) & 0x01);
    }
}
