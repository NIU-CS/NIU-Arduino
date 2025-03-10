#include <Keypad.h>
const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
  };

byte data[ROWS] = {9, 8, 7, 6};
byte scan[COLS] = {2, 3, 4, 5};
Keypad keynum = Keypad(makeKeymap(keys), data, scan, ROWS, COLS);
byte Pass_set[4] = {'0','0','0','0'};
byte Pass_in[4] = {};
int C = 0;
int V = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
   Serial.println("==請輸入密碼==");
   while(1){
    char key = keynum.getKey();
    if(key != NO_KEY){
      if (key >= 48 & key <= 57){
        if (C < 4){
          Pass_in[C] = key;
          C++;
          Serial.print(key);
        }
      }
      if (key == '*'){
        C = 0;
        Serial.println("請重新輸入密碼...");
        Serial.println("==請輸入密碼==");
      }
      if (key == '#'){
        if (C == 4){
          for (int j = 0; j <= 3;j++) Serial.println(Pass_in[j]);
          C = 0;
          for (int i = 0; i <= 3; i++){
            if (Pass_set[i] == Pass_in[i]) V = 1;
            else{
              V = 0;
              Serial.println("密碼錯誤");
              delay(2000);
              break;
            }
          }
        }
      }
      if (V == 1){
        Serial.println("密碼正確，門已打開");
        C = 0;
        V = 0;
        delay(2000);
        break;
      }
    }
   }
}
