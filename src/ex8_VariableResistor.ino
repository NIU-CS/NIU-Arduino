int potPin = A3;
int ledPin = 9;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(potPin);
  Serial.println(sensorValue, DEC);
  analogWrite(ledPin, sensorValue/4);
  delay(100);
}
