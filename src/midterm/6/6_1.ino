int buttonIncrease = 9;
int buttonDecrease = 8;
int value = 0; // 要顯示的數字
unsigned long lastSendTime = 0; // 記錄上次傳送的時間
const unsigned long sendInterval = 100; // 設定傳送間隔(毫秒)

void setup() {
  pinMode(buttonIncrease, INPUT_PULLUP); // 設置按鈕為輸入，並啟用內建上拉電阻
  pinMode(buttonDecrease, INPUT_PULLUP); // 設置按鈕為輸入，並啟用內建上拉電阻
  Serial.begin(9600); // 設置硬體串列通訊速率
}

void loop() {
  // 檢查增加按鈕
  if (digitalRead(buttonIncrease) == LOW) {
    value++;
    if (value > 9) value = 0; // 確保數字不超過 9
    Serial.write(value); // 傳送數字
    delay(300); // 消抖延遲
  }

  // 檢查減少按鈕
  if (digitalRead(buttonDecrease) == LOW) {
    value--;
    if (value < 0) value = 9; // 確保數字不低於 0
    Serial.write(value); // 傳送數字
    delay(300); // 消抖延遲
  }
  
  // 定期傳送當前數字
  if (millis() - lastSendTime >= sendInterval) {
    Serial.write(value); // 傳送當前數字
    lastSendTime = millis(); // 更新上次傳送的時間
  }
}
