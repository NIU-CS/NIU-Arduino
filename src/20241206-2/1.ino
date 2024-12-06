int pwm_pin = 9;

void setup() { pinMode(pwm_pin, OUTPUT); }

void d() { tone(pwm_pin, 440, 100); delay(200); }
void r() { tone(pwm_pin, 494, 100); delay(200); }
void m() { tone(pwm_pin, 523, 100); delay(200); }
void f() { tone(pwm_pin, 587, 100); delay(200); }
void s() { tone(pwm_pin, 659, 100); delay(200); }
void l() { tone(pwm_pin, 698, 100); delay(200); }
void t() { tone(pwm_pin, 784, 100); delay(200); }

void smm() { s(); m(); m(); delay(100); }
void frr() { f(); r(); r(); delay(100); }

void loop() {
    smm();
    frr();
    d(); r(); m(); f(); s(); s(); s(); delay(100);
    smm();
    frr();
    d(); m(); s(); s(); m(); delay(100);
    r(); r(); r(); r(); r(); m(); f(); delay(100);
    m(); m(); m(); m(); m(); f(); s(); delay(100);
    smm();
    frr();
    d(); m(); s(); s(); d(); delay(100);
}
