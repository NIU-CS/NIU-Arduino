// C++ code
//
int PIN = 12;

void setup() { pinMode(PIN, OUTPUT); }

void loop() {
    digitalWrite(PIN, HIGH);  // set PIN 12 HIGH
    delay(1000);              // Wait for 1000 millisecond(s)
    digitalWrite(PIN, LOW);   // set PIN 12 LOW
    delay(1000);              // Wait for 1000 millisecond(s)
}