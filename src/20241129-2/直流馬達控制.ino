const int output_pin = 3;
int pwm_value = 0;
int increment = 5;
int delay_time = 30;
bool increasing = true;

void setup() {
    pinMode(output_pin, OUTPUT);
}

void loop() {
    if (increasing) { // increase
        pwm_value += increment;
        if (pwm_value >= 255) {
            pwm_value = 255;
            increasing = false;
        }
    } else { // decrease
        pwm_value -= increment;
        if (pwm_value <= 0) {
            pwm_value = 0;
            increasing = true;
        }
    }

    analogWrite(output_pin, pwm_value);
    delay(delay_time);
}
