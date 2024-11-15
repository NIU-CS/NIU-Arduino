int led_run[8] = {0, 1, 2, 3, 4, 5, 6, 7};
int sw[4] = {8, 9, 10, 11};
int led_num = 0;
#define ON LOW
#define OFF HIGH
void led_dark() {
    for (led_num = 0; led_num <= 7; led_num++) digitalWrite(led_num, LOW);
}

void left(int x) {
    int i;
    for (i = 0; i < x; i++) {
        for (led_num = 0; led_num <= 7; led_num++) {
            digitalWrite(led_num, LOW);
            delay(200);
            digitalWrite(led_num, HIGH);
        }
    }
}

void right(int x) {
    int i;
    for (i = 0; i < x; i++) {
        for (led_num = 7; led_num >= 0; led_num--) {
            digitalWrite(led_num, LOW);
            delay(200);
            digitalWrite(led_num, HIGH);
        }
    }
}

void alter(int x) {
    int i;
    for (i = 0; i < x; i++) {
        for (led_num = 0; led_num <= 3; led_num++) digitalWrite(led_num, LOW);
        for (led_num = 4; led_num <= 7; led_num++) digitalWrite(led_num, HIGH);
        delay(200);
        for (led_num = 0; led_num <= 3; led_num++) digitalWrite(led_num, HIGH);
        for (led_num = 4; led_num <= 7; led_num++) digitalWrite(led_num, LOW);
        delay(200);
    }
}

void flash(int x) {
    int i;
    for (i = 0; i < x; i++) {
        for (led_num = 0; led_num <= 7; led_num++) digitalWrite(led_num, LOW);
        delay(200);
        for (led_num = 0; led_num <= 7; led_num++) digitalWrite(led_num, HIGH);
        delay(200);
    }
}

void pili(int x) {
    int i;
    for (i = 0; i < x; i++) {
        left(1);
        right(1);
    }
}

void setup() {
    for (led_num = 0; led_num <= 7; led_num++)
        pinMode(led_num, OUTPUT);
    for (led_num = 8; led_num <= 11; led_num++) pinMode(led_num, INPUT);
    led_dark();
}

void loop() {
    if (digitalRead(sw[0]) == ON) {
        alter(5);
        flash(5);
    } else if (digitalRead(sw[1]) == ON) {
        left(5);
        flash(5);
    } else if (digitalRead(sw[2]) == ON) {
        right(5);
        flash(5);
    } else if (digitalRead(sw[3]) == ON) {
        pili(5);
        flash(5);
    } else {
        led_dark();
    }
}
