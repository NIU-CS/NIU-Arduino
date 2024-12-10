int pwm_pin = 9;

void setup() { pinMode(pwm_pin, OUTPUT); }

void d() {
    tone(pwm_pin, 261.626, 100);
    delay(400);
}
void r() {
    tone(pwm_pin, 293.665, 100);
    delay(400);
}
void m() {
    tone(pwm_pin, 329.628, 100);
    delay(400);
}
void f() {
    tone(pwm_pin, 349.228, 100);
    delay(400);
}
void s() {
    tone(pwm_pin, 391.995, 100);
    delay(400);
}
void l() {
    tone(pwm_pin, 440.000, 100);
    delay(400);
}
void t() {
    tone(pwm_pin, 493.883, 100);
    delay(400);
}

void smm() {
    s();
    m();
    m();
    delay(400);
}
void frr() {
    f();
    r();
    r();
    delay(400);
}

void loop() {
    smm();
    frr();
    d();
    r();
    m();
    f();
    s();
    s();
    s();
    delay(400);
    smm();
    frr();
    d();
    m();
    s();
    s();
    m();
    delay(400);
    r();
    r();
    r();
    r();
    r();
    m();
    f();
    delay(400);
    m();
    m();
    m();
    m();
    m();
    f();
    s();
    delay(400);
    smm();
    frr();
    d();
    m();
    s();
    s();
    d();
    delay(400);
}
