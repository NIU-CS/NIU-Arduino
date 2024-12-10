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
        tone(pwm_pin, 261.626, 100);
    }
    // if button press on A1 is detected
    if (digitalRead(A1) == HIGH) {
        tone(pwm_pin, 293.665, 100);
    }
    // if button press on A2 is detected
    if (digitalRead(A2) == HIGH) {
        tone(pwm_pin, 329.628, 100);
    }
    // if button press on A3 is detected
    if (digitalRead(A3) == HIGH) {
        tone(pwm_pin, 349.228, 100);
    }
    // if button press on A4 is detected
    if (digitalRead(A4) == HIGH) {
        tone(pwm_pin, 391.995, 100);
    }
    delay(100);  // Delay a little bit to improve simulation performance
}
