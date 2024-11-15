int led_num[10][7] ={
{3, 4, 5, 6, 7, 8},       //數字　0
{4, 5},                   //數字　1
{3, 4, 6, 7, 9},          //數字　2
{3, 4, 5, 6, 9},          //數字　3
{4, 5, 8, 9},             //數字　4
{3, 5, 6, 8, 9},          //數字　5
{3, 5, 6, 7, 8, 9, 10},   //數字　6
{3, 4, 5},                //數字　7                      
{3, 4, 5, 6, 7, 8, 9},    //數字　8
{3, 4, 5, 6, 8, 9, 10}    //數字　9
                    };    
int num=0;             //數字變數
int segment=0;         //LED腳位變數

void led_dark()      //將7段顯示器LED全部熄滅
{
  for(segment=3;segment<=10;segment++)
    digitalWrite(segment, HIGH); 
  delay(1000);
}
void setup()
{
  for(segment=3;segment<=10;segment++) 
    pinMode(segment,OUTPUT);    //接腳設定輸出 
}

void loop()
{
  led_dark();   //將7段顯示器LED全部熄滅
  for(num=0;num<10;num++)
  {
    for(segment=0;segment<7;segment++)    //每1秒切換顯示數字  0～9 
      digitalWrite(led_num[num][segment], LOW); 
    delay(1000);
    led_dark();   //將7段顯示器LED全部熄滅
  }
}

