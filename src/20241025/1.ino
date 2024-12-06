const int tempPin = A0;  // 溫度傳感器連接的模擬引腳

void setup() {
    Serial.begin(9600);  // 設置串行通信
}

void loop() {
    int tempValue = analogRead(tempPin);         // 讀取溫度值
    float voltage = tempValue * (5.0 / 1023.0);  // 將讀數轉換為電壓
    float temperature = (voltage - 0.5) * 100;   // 將電壓轉換為溫度 (攝氏)

    Serial.println(temperature);  // 將溫度數據傳輸給 UNO2
    delay(1000);                  // 每秒傳輸一次數據
}
