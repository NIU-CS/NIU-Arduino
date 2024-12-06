int pwm_pin = 9;

void setup() {
    pinMode(pwm_pin, OUTPUT);
    pinMode(A0, INPUT);
    pinMode(A1, INPUT);
    pinMode(A2, INPUT);
}

void loop() {
    // if button press on A0 is detected
    if (digitalRead(A0) == HIGH) {
        tone(pwm_pin, 440, 100);  // play tone 57 (A4 = 440 Hz)
    }
    // if button press on A1 is detected
    if (digitalRead(A1) == HIGH) {
        tone(pwm_pin, 494, 100);  // play tone 59 (B4 = 494 Hz)
    }
    // if button press on A2 is detected
    if (digitalRead(A2) == HIGH) {
        tone(pwm_pin, 523, 100);  // play tone 60 (C5 = 523 Hz)
    }
    // if button press on A3 is detected
    if (digitalRead(A3) == HIGH) {
        tone(pwm_pin, 587, 100);  // play tone 62 (D5 = 587 Hz)
    }
    // if button press on A4 is detected
    if (digitalRead(A4) == HIGH) {
        tone(pwm_pin, 659, 100);  // play tone 64 (E5 = 659 Hz)
    }
    delay(10);  // Delay a little bit to improve simulation performance
}
