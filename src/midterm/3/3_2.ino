// R_Uno_TXRX
#include <SoftwareSerial.h>
int count = 0;
SoftwareSerial mySerial(2,3); // 宣告 mySerial 物件並指定 RX, TX
int LED_Pin = 13;             // 宣告 DIO 13 腳位為 LED 腳位

void LED_blink() {             // 宣告自訂的 LED 閃爍函式
  digitalWrite(LED_Pin,HIGH);  // 呼叫此函式輸出高電位使 LED 點亮為 5V
  delay(200);                  // 呼叫延遲函式延遲 200 毫秒
  digitalWrite(LED_Pin,LOW);   // 呼叫此函式輸出低電位為 0V
  delay(200);                  // 呼叫延遲函式延遲 200 毫秒
}
// 結束 LED_blink() 函式

void setup() {                 // 只會執行一次的程式初始化函式
  pinMode(LED_Pin,OUTPUT);     // 規劃 LED 腳輸出模式
  pinMode(8,OUTPUT);           // 設定腳位 8 為輸出
  pinMode(9,OUTPUT);           // 設定腳位 9 為輸出
  Serial.begin(9600);          // 將串列通訊觸發率設定為 9600 bps
  mySerial.begin(4800);        // 設定 SoftwareSerial 串列觸發率為 4800 bps
}
// 結束 setup() 函式

void loop() {                  // 永遠迴圈執行的主控制函式
  while (!mySerial.available()) { // 等待串列接收資料，未收到資料時會執行下一行
    Serial.println("...");
  }
  Serial.println(mySerial.read()); // 顯示接收到的資料

  // 判斷是否為接收到的資料 'Y'
  if (mySerial.read() == 'Y') {
    LED_blink(); LED_blink();      // 如果是則呼叫 LED 閃爍函式 2 次

    if (count % 2 == 0) {          // 判斷計數器是否為偶數
      digitalWrite(8,HIGH);        // 亮綠燈
      digitalWrite(9,LOW);
    }
    if (count % 2 == 1) {          // 判斷計數器是否為奇數
      digitalWrite(9,HIGH);        // 亮紅燈
      digitalWrite(8,LOW);
    }
    count++;
  } // 結束 if 判斷

  // 命令串列傳出單元字 'Y'，以觸發 L_Uno 板的 LED 閃爍
  mySerial.write('Y');
  delay(2000);                     // 等待 2 秒
}
// 結束 loop() 函式
