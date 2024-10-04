int led_run[8] = {0, 1, 2, 3, 4, 5, 6, 7};
int sw[4] = {8, 9, 10, 11};
int led_num = 0;
int value = 0;
int segPins[7] = {0, 1, 2, 3, 4, 5, 6};  // 七段顯示器的引腳

#define ON LOW
#define OFF HIGH

// 七段顯示器的數位對應，十六進制 0~F
const int hexDigits[16][7] = {
    {1, 1, 1, 1, 1, 1, 0},  // 0
    {0, 1, 1, 0, 0, 0, 0},  // 1
    {1, 1, 0, 1, 1, 0, 1},  // 2
    {1, 1, 1, 1, 0, 0, 1},  // 3
    {0, 1, 1, 0, 0, 1, 1},  // 4
    {1, 0, 1, 1, 0, 1, 1},  // 5
    {1, 0, 1, 1, 1, 1, 1},  // 6
    {1, 1, 1, 0, 0, 0, 0},  // 7
    {1, 1, 1, 1, 1, 1, 1},  // 8
    {1, 1, 1, 1, 0, 1, 1},  // 9
    {1, 1, 1, 0, 1, 1, 1},  // A
    {0, 0, 1, 1, 1, 1, 1},  // b
    {1, 0, 0, 1, 1, 1, 0},  // C
    {0, 1, 1, 1, 1, 0, 1},  // d
    {1, 0, 0, 1, 1, 1, 1},  // E
    {1, 0, 0, 0, 1, 1, 1}   // F
};

void displayNumber(int num) {
    num = num & 0xF;
    for (int i = 0; i < 7; i++) {
        digitalWrite(segPins[i], hexDigits[num][i]);
    }
}

void led_dark() {
    for (led_num = 0; led_num <= 7; led_num++) {
        digitalWrite(led_num, LOW);
    }
}

void setup() {
    for (led_num = 0; led_num <= 7; led_num++)
        pinMode(led_num, OUTPUT);
    for (led_num = 8; led_num <= 11; led_num++) pinMode(led_num, INPUT);
    for (int i = 0; i < 7; i++) {
        pinMode(segPins[i], OUTPUT);
    }

    led_dark();
    displayNumber(value);
}

void loop() {
    if (digitalRead(sw[0]) == ON) {  // +2
        value += 2;
        displayNumber(value);
        delay(200);
    } else if (digitalRead(sw[1]) == ON) {  // +1
        value += 1;
        displayNumber(value);
        delay(200);
    } else if (digitalRead(sw[2]) == ON) {  // -1
        value -= 1;
        displayNumber(value);
        delay(200);
    } else if (digitalRead(sw[3]) == ON) {  // -2
        value -= 2;
        displayNumber(value);
        delay(200);
    }

    delay(100);
}
