// UNO2 使用硬體串列，其 0 (RX), 1 (TX) 接到 UNO3 的 1 (TX), 0 (RX)

void setup() {
  Serial.begin(9600); // 用於與 UNO3 通訊

  delay(1000); // 確保 UNO1 的資料已經發送完畢

  // 模擬猜拳結果，假設 1 代表剪刀，2 代表石頭，3 代表布
  int result = random(1, 4);
  Serial.write(result); // 傳送結果給 UNO3
  Serial.print("UNO2 的出拳結果: ");
  Serial.println(result);
}

void loop() {
  // UNO2 也只需傳送一次結果
}
