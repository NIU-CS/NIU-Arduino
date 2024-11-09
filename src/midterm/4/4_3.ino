#include <SoftwareSerial.h>

// UNO3 的 2 (RX), 3 (TX) 腳位分別接到 UNO1 的 3 (TX), 2 (RX)
SoftwareSerial uno1Serial(2, 3); // RX, TX

int uno1Result = 0;
int uno2Result = 0;

void setup() {
  Serial.begin(9600);    // 與 UNO2 通訊
  uno1Serial.begin(9600); // 與 UNO1 通訊
}

void loop() {
  // 接收 UNO1 的結果
  if (uno1Serial.available() > 0) {
    uno1Result = uno1Serial.read();
  }

  // 接收 UNO2 的結果
  if (Serial.available() > 0) {
    uno2Result = Serial.read();
  }

  // 判斷結果
  if (uno1Result != 0 && uno2Result != 0) {
    int winner = judgeWinner(uno1Result, uno2Result);
    if (winner == 1) {
      Serial.println("1");
    } else if (winner == 2) {
      Serial.println("2");
    } else {
      Serial.println("0");
    }
    uno1Result = 0;
    uno2Result = 0;
  }
}

int judgeWinner(int r1, int r2) {
  if (r1 == r2) return 0;         // 平手
  if ((r1 == 1 && r2 == 3) || 
      (r1 == 2 && r2 == 1) || 
      (r1 == 3 && r2 == 2)) {
    return 1; // UNO1 勝
  } else {
    return 2; // UNO2 勝
  }
}
