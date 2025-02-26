int lowPin = 5;
int highPin = 12;

void setup() {
  for (int NowPin = lowPin; NowPin <= highPin; NowPin++){
    pinMode(NowPin, OUTPUT);
    }

  for (int NowPin = lowPin; NowPin <= highPin; NowPin++){
    digitalWrite(NowPin, HIGH);
    }
}

void loop() {
  for (int NowPin = lowPin; NowPin <= highPin; NowPin++){
    digitalWrite(NowPin, LOW);
    delay(500);
    digitalWrite(NowPin, HIGH);
    delay(500);
    }
}
