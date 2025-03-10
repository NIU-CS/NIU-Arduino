int digit1 = 12;
int digit2 = 11;
int digit3 = 10;
int digit4 = 9;
int segA = 2;
int segB = 3;
int segC = 4;
int segD = 5;
int segE = 6;
int segF = 7;
int segG = 8;
byte seven_seg_digits[10][7] = {
    {1, 1, 1, 1, 1, 1, 0}, // 0
    {0, 1, 1, 0, 0, 0, 0}, // 1
    {1, 1, 0, 1, 1, 0, 1}, // 2
    {1, 1, 1, 1, 0, 0, 1}, // 3
    {0, 1, 1, 0, 0, 1, 1}, // 4
    {1, 0, 1, 1, 0, 1, 1}, // 5
    {1, 0, 1, 1, 1, 1, 1}, // 6
    {1, 1, 1, 0, 0, 0, 0}, // 7
    {1, 1, 1, 1, 1, 1, 1}, // 8
    {1, 1, 1, 1, 0, 1, 1}  // 9
};

void setup() {
    pinMode(segA, OUTPUT);
    pinMode(segB, OUTPUT);
    pinMode(segC, OUTPUT);
    pinMode(segD, OUTPUT);
    pinMode(segE, OUTPUT);
    pinMode(segF, OUTPUT);
    pinMode(segG, OUTPUT);
    pinMode(digit1, OUTPUT);
    pinMode(digit2, OUTPUT);
    pinMode(digit3, OUTPUT);
    pinMode(digit4, OUTPUT);
}

void loop() {
    displayNumber(millis()/1000);
}

void displayNumber(int toDisplay) {
    #define DIGIT_ON HIGH
    #define DIGIT_OFF LOW
    for (int digit = 1; digit < 5; digit++) {
        switch(digit) {
            case 1:
                digitalWrite(digit4, HIGH);
                lightNumber(toDisplay % 10);
                toDisplay /= 10;
                break;
            case 2:
                digitalWrite(digit3, HIGH);
                lightNumber(toDisplay % 6);
                toDisplay /= 6;
                break;
            case 3:
                digitalWrite(digit2, HIGH);
                lightNumber(toDisplay % 10);
                toDisplay /= 10;
                break;
            case 4:
                digitalWrite(digit1, HIGH);
                lightNumber(toDisplay % 6);
                toDisplay /= 6;
                break;
        }
        delayMicroseconds(6000);
    lightNumber(10);
    digitalWrite(digit4, LOW);
    digitalWrite(digit3, LOW);
    digitalWrite(digit2, LOW);
    digitalWrite(digit1, LOW);
    }
}

void lightNumber(byte numberToDisplay) {
    byte pin = 2;
    for (byte seg = 0; seg < 7; ++seg) {
        digitalWrite(pin, seven_seg_digits[numberToDisplay][seg]);
        ++pin;
    }
}
