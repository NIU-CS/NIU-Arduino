int LED_Pin = 13;  // 設定 LED 連接的腳位為 13

// 自訂函式，用來控制 LED 閃爍
void LED_blink() {
  digitalWrite(LED_Pin, HIGH);  // 開啟 LED
  delay(200);                   // 延遲 200 毫秒
  digitalWrite(LED_Pin, LOW);   // 關閉 LED
  delay(200);                   // 再延遲 200 毫秒
}

void setup() {
  pinMode(LED_Pin, OUTPUT);     // 設定 LED_Pin 為輸出模式
  Serial.begin(4800);           // 設定序列通訊速度為 4800 bps
}

void loop() {
  while (!Serial.available()) {
    // 等待接收到來自另一台 Arduino 的資料
  }
  if (Serial.read() == 'Y') {   // 如果收到字元 'Y'
    LED_blink();                // 執行兩次 LED 閃爍
    LED_blink();
  }
  Serial.write('Y');            // 回傳字元 'Y' 給另一台 Arduino
  delay(2000);                  // 延遲 2 秒後再等待新的資料
}
