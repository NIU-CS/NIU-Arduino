int pin[7];

byte seven_seg[10][7] = {
  {1, 1, 1, 1, 1, 1, 0}, // 0
  {0, 1, 1, 0, 0, 0, 0}, // 1
  {1, 1, 0, 1, 1, 0, 1}, // 2
  {1, 1, 1, 1, 0, 0, 1}, // 3
  {0, 1, 1, 0, 0, 1, 1}, // 4
  {1, 0, 1, 1, 0, 1 ,1}, // 5
  {1, 0, 1, 1, 1, 1, 1}, // 6
  {1, 1, 1, 0, 0, 0, 0}, // 7
  {1, 1, 1, 1, 1 ,1, 1}, // 8
  {1, 1, 1, 1, 0, 1, 1}, // 9
};

void setup() {
  for (int i=2; i<10; i++) {
    pin[i-2] = i;
    pinMode(pin[i-2], OUTPUT);
  }
  digitalWrite(pin[6], 0);
}

void loop() {
  for (byte digit = 0; digit < 10; ++digit) {
    delay(1000);
    CodeWrite(digit);
  }

  delay(2000);
}

void CodeWrite(byte digit) {
  byte pin = 2;
  for (byte seg = 0; seg < 8; ++seg) {
    digitalWrite(pin, seven_seg[digit][seg]);
    ++pin;
  }
}
