const int redPin = 11;
const int greenPin = 10;
const int bluePin = 9;

void setup() {
  // put your setup code here, to run once:
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void setRGB(int r, int g, int b) {
  analogWrite(redPin, r);
  analogWrite(greenPin, g);
  analogWrite(bluePin, b);
}

void loop() {
  // put your main code here, to run repeatedly:
  setRGB(0, 0, 0);
  delay(1000);
  setRGB(255, 0, 0);
  delay(1000);
  setRGB(0, 255, 0);
  delay(1000);
  setRGB(0, 0, 255);
  delay(1000);
  setRGB(255, 255, 255);
  delay(1000);
}
