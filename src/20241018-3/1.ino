#include <SoftwareSerial.h>

SoftwareSerial mySerial(2, 3); // RX, TX

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);
  randomSeed(analogRead(0)); // 初始化隨機種子
}

void loop() {
  int randomValue = random(0, 16); // 產生0到15的隨機數
  mySerial.write(randomValue); // 發送隨機數給第二塊板子
  delay(1000); // 延遲1秒
}
