#include <SoftwareSerial.h>

SoftwareSerial mySerial(0, 1); // RX, TX
int LED_Pin = 13;
int randomNumber;
bool isMyTurn = true;  // 控制是否該傳送亂數的標誌

// 宣告 7 段顯示器的腳位對應 a, b, c, d, e, f, g 段
int segmentPins[7] = {4, 5, 7, 8, 9, 11, 10};  // a, b, c, d, e, f, g 腳位

// 每個數字對應的段位狀態 (1 表示亮, 0 表示暗)
// 從 0 到 15 對應的顯示數字或字母
byte numberPatterns[16] = {
  // g f e d c b a
  0b00111111,  // 0
  0b00000110,  // 1
  0b01011011,  // 2
  0b01001111,  // 3
  0b01100110,  // 4
  0b01101101,  // 5
  0b01111101,  // 6
  0b00000111,  // 7
  0b01111111,  // 8
  0b01101111,  // 9
  0b01110111,  // A
  0b01111100,  // b
  0b00111001,  // C
  0b01011110,  // d
  0b01111001,  // E
  0b01110001   // F
};

// 初始化 7 段顯示器的腳位
void setupDisplay() {
  for (int i = 0; i < 7; i++) {
    pinMode(segmentPins[i], OUTPUT);
  }
}

// 顯示數字的函式，控制 7 段顯示器的每個段位
void displayNumber(int number) {
  byte pattern = numberPatterns[number];  // 取出對應數字的段位模式
  for (int i = 0; i < 7; i++) {
    digitalWrite(segmentPins[i], (pattern >> i) & 0x01);  // 根據模式亮起對應段位
  }
}

void LED_blink() {
  digitalWrite(LED_Pin, HIGH);
  delay(200);
  digitalWrite(LED_Pin, LOW);
  delay(200);
}

void setup() {
  pinMode(LED_Pin, OUTPUT);
  Serial.begin(9600);
  mySerial.begin(4800);
  randomSeed(analogRead(0));  // 使用未連接的腳位來產生亂數種子
  setupDisplay();
}

void loop() {
  if (isMyTurn) {
    // 產生亂數並傳送給對方
    randomNumber = random(0, 16);  // 產生 0-15 之間的亂數
    mySerial.write(randomNumber);  // 傳送亂數
    Serial.print("Sent number: ");
    Serial.println(randomNumber);  // 在監看視窗顯示傳送的數字
    
    // 等待對方回傳確認訊號 'Y'
    while (!mySerial.available()) {}
    
    if (mySerial.read() == 'Y') {
      LED_blink(); LED_blink();
      Serial.println("Number received and acknowledged.");
    }
    isMyTurn = false;  // 結束自己的回合，輪到對方
  } else {
    // 接收對方傳來的亂數並顯示
    while (!mySerial.available()) {}  // 等待接收亂數
    randomNumber = mySerial.read();  // 讀取接收到的亂數
    Serial.print("Received number: ");
    Serial.println(randomNumber);  // 在監看視窗顯示接收的數字
    
    // 顯示亂數在 7 段顯示器上
    displayNumber(randomNumber);
    
    // 回傳確認訊號 'Y'
    mySerial.write('Y');
    
    LED_blink(); LED_blink();  // 讓 LED 閃爍
    isMyTurn = true;  // 完成接收後，輪到自己傳送
  }
  
  delay(2000);  // 兩秒間隔
}
