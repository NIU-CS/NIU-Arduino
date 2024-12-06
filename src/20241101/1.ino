// 腳位定義
const int buttonPin1 = 2;  // 增加數值
const int buttonPin2 = 3;  // 減少數值
const int maxValue = 9;
const int minValue = 0;

int counter = 0;

// 定義七段顯示器段位 (A 到 G 和 DP)
int segmentPins[] = {4, 5, 6, 7, 8, 9, 10};  // A到G的腳位
int digitValues[10][7] = {
    {1, 1, 1, 1, 1, 1, 0},  // 0
    {0, 1, 1, 0, 0, 0, 0},  // 1
    {1, 1, 0, 1, 1, 0, 1},  // 2
    {1, 1, 1, 1, 0, 0, 1},  // 3
    {0, 1, 1, 0, 0, 1, 1},  // 4
    {1, 0, 1, 1, 0, 1, 1},  // 5
    {1, 0, 1, 1, 1, 1, 1},  // 6
    {1, 1, 1, 0, 0, 0, 0},  // 7
    {1, 1, 1, 1, 1, 1, 1},  // 8
    {1, 1, 1, 1, 0, 1, 1}   // 9
};

// 初始化
void setup() {
    // 設置按鈕為輸入
    pinMode(buttonPin1, INPUT_PULLUP);
    pinMode(buttonPin2, INPUT_PULLUP);

    // 設置七段顯示器段位為輸出
    for (int i = 0; i < 7; i++) {
        pinMode(segmentPins[i], OUTPUT);
    }

    // 設置中斷
    attachInterrupt(digitalPinToInterrupt(buttonPin1), incrementCounter,
                    FALLING);
    attachInterrupt(digitalPinToInterrupt(buttonPin2), decrementCounter,
                    FALLING);

    // 初始顯示
    displayDigit(counter);
}

// 增加數值函數
void incrementCounter() {
    if (counter < maxValue) {
        counter++;
        displayDigit(counter);
    }
}

// 減少數值函數
void decrementCounter() {
    if (counter > minValue) {
        counter--;
        displayDigit(counter);
    }
}

// 顯示數字
void displayDigit(int number) {
    for (int i = 0; i < 7; i++) {
        digitalWrite(segmentPins[i], digitValues[number][i]);
    }
}

void loop() {
    // 主迴圈保持空白，因為所有功能都透過中斷完成
}
