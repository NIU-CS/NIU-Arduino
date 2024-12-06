// 部分範例參考自
// https://www.youtube.com/watch?v=5uYsI_cLvSM
// https://www.tinkercad.com/things/0C1DmRyZ402-copy-of-/editel?tenant=circuits

/*
        http://www.taichi-maker.com/homepage/reference-index/arduino-code-reference/tone/
    tone(pin, frequency)
        tone(pin, frequency, duration)
    pin: 發聲腳位(該腳位需要連接蜂鳴器)
    frequency: 發聲頻率(赫茲)-無符號整數型態
    duration: 發聲時長(微秒，此參數不為必須)
*/

const int gas = 0;
int led_pin = 2;
int green_led_pin = 3;
int read_pin = A5;
int tone_pin = 6;

float getsensorValue(int pin) { return (analogRead(pin)); }

void setup() {
    pinMode(tone_pin, OUTPUT);
    pinMode(led_pin, OUTPUT);
    pinMode(green_led_pin, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    float sensorValue;
    sensorValue = analogRead(read_pin);
    if (sensorValue >= 470) {
        digitalWrite(led_pin, HIGH);
        digitalWrite(tone_pin, HIGH);
        digitalWrite(green_led_pin, LOW);
        Serial.print(sensorValue);
        Serial.println("|SMOKE DETECTED");
    } else {
        digitalWrite(led_pin, LOW);
        digitalWrite(tone_pin, LOW);
        digitalWrite(green_led_pin, HIGH);
        Serial.println("Sensor Value:");
        Serial.println(sensorValue);
    }
    delay(100);
}
// 作業請加上蜂鳴器效果，LED亮紅燈時蜂鳴器也叫
// 當煙霧越大則LED紅燈亮，當沒有偵測到煙霧時亮綠燈
// 也請加上綠燈