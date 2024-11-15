const int ledPins[10] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11}; // LED 對應的數位引腳
float minTemp = 0; // 假設的最低溫度
float maxTemp = 50; // 假設的最高溫度

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 10; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  if (Serial.available() > 0) {
    float temperature = Serial.parseFloat(); // 讀取溫度數據
    int numLeds = map(temperature, minTemp, maxTemp, 0, 10); // 映射溫度到 LED 數量

    for (int i = 0; i < 10; i++) {
      if (i < numLeds) {
        digitalWrite(ledPins[i], HIGH); // LED 亮
      } else {
        digitalWrite(ledPins[i], LOW); // LED 關
      }
    }
  }
}
