int ledPin1 = 11;
int ledPin2 = 12;
void setup() {
  pinMode(ledPin1,OUTPUT);
  pinMode(ledPin2,OUTPUT);
}

void loop() {
  digitalWrite(ledPin1,HIGH);
  digitalWrite(ledPin2,LOW);
  delay(1000);
  digitalWrite(ledPin1,LOW);
  digitalWrite(ledPin2,HIGH);
  delay(1000);
}
