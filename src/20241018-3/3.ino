#include <SoftwareSerial.h>

SoftwareSerial mySerial(13, 12);                     // RX, TX
const int segmentPins[7] = {4, 5, 7, 8, 9, 10, 11};  // 七段顯示器的各段接腳
// 定義16進制0~F的七段顯示器編碼
const byte hexDigits[16] = {
    0b00111111,  // 0
    0b00000110,  // 1
    0b01011011,  // 2
    0b01001111,  // 3
    0b01100110,  // 4
    0b01101101,  // 5
    0b01111101,  // 6
    0b00000111,  // 7
    0b01111111,  // 8
    0b01101111,  // 9
    0b01110111,  // A
    0b01111100,  // B
    0b00111001,  // C
    0b01011110,  // D
    0b01111001,  // E
    0b01110001   // F
};

void setup() {
    Serial.begin(9600);
    mySerial.begin(9600);
    for (int i = 0; i < 7; i++) {
        pinMode(segmentPins[i], OUTPUT);
    }
}

void loop() {
    if (mySerial.available()) {  // 檢查來自第二塊板子的數據
        int value = mySerial.read();
        displayHex(value);  // 在七段顯示器上顯示16進制數
    }
}

void displayHex(int num) {
    byte segments = hexDigits[num];
    for (int i = 0; i < 7; i++) {
        digitalWrite(segmentPins[i], (segments >> i) & 0x01);
    }
}
