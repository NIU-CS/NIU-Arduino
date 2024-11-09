const int greenLED = 7;   // 綠燈接腳
const int yellowLED = 8; // 黃燈接腳
const int redLED = 9;    // 紅燈接腳
const int potentiometerPin = A0; // 電位器接腳

void setup() {
    pinMode(greenLED, OUTPUT);
    pinMode(yellowLED, OUTPUT);
    pinMode(redLED, OUTPUT);
}

void loop() {
    int sensorValue = analogRead(potentiometerPin); // 讀取電位器值

    // 關閉所有燈
    digitalWrite(greenLED, LOW);
    digitalWrite(yellowLED, LOW);
    digitalWrite(redLED, LOW);

    // 根據電位器的值控制不同燈的亮起
    if (sensorValue >= 0 && sensorValue <= 341) {
        digitalWrite(greenLED, HIGH); // 亮綠燈
    } else if (sensorValue >= 342 && sensorValue <= 682) {
        digitalWrite(yellowLED, HIGH); // 亮黃燈
    } else if (sensorValue >= 683 && sensorValue <= 1023) {
        digitalWrite(redLED, HIGH); // 亮紅燈
    }

    delay(500); // 亮暗之間的距離 0.5 秒
}
