int ledPin = 9;       // LED接在第9隻接腳
int sensorValue = 0;  // 類比數值
int led_Value = 0;    // 控制LED亮度的數值
float voltage = 0;    // 轉換為電壓值

void setup() {
    pinMode(ledPin, OUTPUT);  // 設定ledPin接腳為輸出
    Serial.begin(9600);       // 設定RS232埠傳輸率9600觀看輸入輸入電壓值
}

void loop() {
    sensorValue = analogRead(A0);  // 讀類比輸入A0類比數值
    led_Value = 255 - sensorValue / 4;
    // 將類比數值除4從10位於轉換為8位元，
    // 並用255來減使數值大小相反，滿足LED亮度控制需求
    voltage = sensorValue * (5.0 / 1023.0);
    // 將類比讀值 (0 - 1023) 轉換為電壓值 (0 - 5V)
    Serial.println("voltage=");  // 在串列監視器顯示voltage=
    Serial.println(voltage);     // 在串列監視器顯示電壓值
    Serial.print("\n");          // 在串列監視器跳行
    // 列印電壓值在螢幕上，可用 Tools->Serial Monitor 觀看
    analogWrite(ledPin, led_Value);  // 寫入PWM數值到 LED 接腳
    delay(300);                      // 等待 300 milliseconds
}
