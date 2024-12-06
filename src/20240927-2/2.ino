const int ledPin1 = 0;
const int ledPin2 = 1;
const int ledPin3 = 2;
const int ledPin4 = 3;
const int dipsw1 = 8;
const int dipsw2 = 9;
const int dipsw3 = 10;
const int dipsw4 = 11;

void setup() {
    // 初始化 LED pins 為輸出
    pinMode(ledPin1, OUTPUT);
    pinMode(ledPin2, OUTPUT);
    pinMode(ledPin3, OUTPUT);
    pinMode(ledPin4, OUTPUT);

    // 初始化 DIP 開關 pins 為輸入
    pinMode(dipsw1, INPUT);
    pinMode(dipsw2, INPUT);
    pinMode(dipsw3, INPUT);
    pinMode(dipsw4, INPUT);
}

void loop() {
    // 儲存 DIP 開關狀態
    int dipswState = 0;

    // 讀取每個 DIP 開關並將其轉換為整數的一部分
    dipswState |= digitalRead(dipsw1) << 0;  // 第一個開關位於最低位
    dipswState |= digitalRead(dipsw2) << 1;  // 第二個開關位於第二位
    dipswState |= digitalRead(dipsw3) << 2;  // 第三個開關位於第三位
    dipswState |= digitalRead(dipsw4) << 3;  // 第四個開關位於第四位

    // 根據 dipswState 的二進位值控制 LED
    digitalWrite(ledPin1, dipswState & 0b0001);  // 控制 LED1
    digitalWrite(ledPin2, dipswState & 0b0010);  // 控制 LED2
    digitalWrite(ledPin3, dipswState & 0b0100);  // 控制 LED3
    digitalWrite(ledPin4, dipswState & 0b1000);  // 控制 LED4
}
