int led_pwm = 9;  // LED 接在第 9 隻接腳
const unsigned int originPwnVal = 99;
unsigned int pwmVal = originPwnVal;  // 輸出 pwm 數值的變數
unsigned int bright_ctr = 0;         // 計數器數值
int wait = 50;  // 50ms (.05 second) delay; shorten for faster fades

void led_dark() {  // 將 LED 熄滅
    digitalWrite(led_pwm, HIGH);
    delay(1000);
}
void setup() {
    pinMode(led_pwm, OUTPUT);  // 設定 led_pwm 接腳為輸出
    led_dark();
    Serial.begin(9600);  // 設定 RS232 埠傳輸率 9600 觀看 PWM 數值
}
void loop() {
    bright_ctr += 1;                      // 用計數器設定PWM數值範圍
    if (bright_ctr < originPwnVal + 1) {  // 計數器從 1 到 originPwnVal
        pwmVal -= 1;                      // PWM數值從 255 遞減，LED 亮度會漸暗
    } else if (bright_ctr <
               originPwnVal * 2 +
                   1) {  // 計數器從 originPwnVal + 1 到 originPwnVal*2 - 2
        pwmVal += 1;     // PWM 數值從 0 遞增，LED 亮度會漸亮
    } else {             // 重置計數器 bright_ctr 為 1，讓 LED 漸暗
        bright_ctr = 0;
        pwmVal = originPwnVal;
        led_dark();
    }
    analogWrite(led_pwm, pwmVal);  // 寫入 pwmVal 數值到 LED 接腳
    Serial.print("PWM:");          // 在串列監視器顯示 PWM:
    Serial.print(pwmVal);          // 在串列監視器顯示 PWM 數值
    Serial.print("\n");            // 在串列監視器顯示跳行
    delay(wait);                   // 等待 'wait' milliseconds
}
