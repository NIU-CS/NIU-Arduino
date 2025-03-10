#include <Keypad.h>
const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
  };

byte data[ROWS] = {9, 8, 7,6};
byte scan[COLS] = {2, 3, 4, 5};
Keypad keynum = Keypad(makeKeymap(keys), data, scan, ROWS, COLS);

void setup() {
  Serial.begin(9600);
}

void loop() {
  char key = keynum.getKey();
  if (key != NO_KEY){
    Serial.println(key);
    }
}
