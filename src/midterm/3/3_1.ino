// L_Uno板上的TXRX串列通訊程式
// 加入函式庫標頭檔
// 透過softwareSerial可以使用一般pin腳位做訊號傳輸
#include <SoftwareSerial.h>
SoftwareSerial mySerial(2,3);   // 宣告mySerial物件變數並指定RX, TX

int LED_Pin=13;                 // 宣告DIO 13腳位為LED腳位

void LED_blink(){               // 使用者自訂的LED閃爍函式
    digitalWrite(LED_Pin,HIGH); // 呼叫數位輸出函式使LED腳為5V
    delay(200);                 // 呼叫延遲函式等200毫秒
    digitalWrite(LED_Pin,LOW);  // 呼叫數位輸出函式使LED腳為0V
    delay(200);                 // 呼叫延遲函式等200毫秒
}

void setup() {                  // 只會執行一次的程式初始化
    pinMode(LED_Pin,OUTPUT);    // 規劃LED腳為輸出模式
    Serial.begin(9600);         // 將串列埠通訊鮑率設為9600bps
    mySerial.begin(4800);       // 將SoftwareSerial鮑率設為9600bps
}                               // 結束setup()函式

void loop(){                    // 永遠迴圈開始的主控制程式
    mySerial.write("Y");        // 傳送序列字元Y
    while(!mySerial.available()){ 
        mySerial.write("Y");    // 當R Uno接收Y的訊號才會執行下一行
    }
    if(mySerial.read()=='Y'){   // 判斷接收的資料是否為字元'Y'
        LED_blink(); LED_blink(); 
        Serial.println("Job Completed! Sir."); // 回報到監看視窗
    }                           // 結束if判斷
    delay(2000);                // 延遲2000毫秒
}                               // 結束loop()函式
