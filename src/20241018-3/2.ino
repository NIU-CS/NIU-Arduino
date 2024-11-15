#include <SoftwareSerial.h>

SoftwareSerial mySerial1(2, 3); // 與第一塊板子的通訊端口
SoftwareSerial mySerial2(4, 5); // 與第三塊板子的通訊端口

void setup() {
  Serial.begin(9600);
  mySerial1.begin(9600);
  mySerial2.begin(9600);
}

void loop() {
  if (mySerial1.available()) { // 檢查來自第一塊板子的數據
    int value = mySerial1.read(); // 讀取數據
    mySerial2.write(value); // 將數據傳給第三塊板子
  }
}
