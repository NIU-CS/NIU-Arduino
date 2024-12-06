#include <SoftwareSerial.h>

// UNO1 的 2 (RX), 3 (TX) 腳位分別接到 UNO3 的 3 (TX), 2 (RX)
SoftwareSerial mySerial(2, 3);  // RX, TX

void setup() {
    Serial.begin(9600);    // 用於本地除錯
    mySerial.begin(9600);  // 用於與 UNO3 通訊

    // 模擬猜拳結果，假設 1 代表剪刀，2 代表石頭，3 代表布
    int result = random(1, 4);
    mySerial.write(result);  // 傳送結果給 UNO3
    Serial.print("UNO1 的出拳結果: ");
    Serial.println(result);
}

void loop() {
    // UNO1 只需要傳送一次結果，因此 loop 中無需額外程式碼
}
