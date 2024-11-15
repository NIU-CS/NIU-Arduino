int led_run[2][8] = { 
    {3, 4, 5, 6, 7, 8, 9, 10},  // 左移 
    {10, 9, 8, 7, 6, 5, 4, 3}   // 右移
};
int led_num=0;
int l_or_r=0;

void led_dark() {
    for(led_num=0; led_num<8; led_num++) {
        digitalWrite(led_run[0][led_num], HIGH); // 全部LED亮
    }
}

void setup() {
    for(led_num=0; led_num<8; led_num++) {
        pinMode(led_run[0][led_num], OUTPUT);   // 設定腳位為輸出
    }
}

void loop() {
    // 全亮
    led_dark();
    delay(1000);

    // 左半部分熄滅，右半保持亮著
    for(led_num=0; led_num<4; led_num++) {
        digitalWrite(led_run[0][led_num], LOW);  // 左邊的LED熄滅
    }
    delay(1000);

    // 右半部分熄滅，左半保持亮著
    for(led_num=4; led_num<8; led_num++) {
        digitalWrite(led_run[0][led_num], LOW);  // 右邊的LED熄滅
    }
    delay(1000);

    // 全亮
    led_dark();
    delay(1000);

    // 右半部分熄滅，左半保持亮著
    for(led_num=4; led_num<8; led_num++) {
        digitalWrite(led_run[0][led_num], LOW);  // 右邊的LED熄滅
    }
    delay(1000);

    // 左半部分熄滅，右半保持亮著
    for(led_num=0; led_num<4; led_num++) {
        digitalWrite(led_run[0][led_num], LOW);  // 左邊的LED熄滅
    }
    delay(1000);
}