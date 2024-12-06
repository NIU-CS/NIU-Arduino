// 定義 7 段顯示器的引腳
int segPins[7] = {2, 3, 4, 5, 6, 7, 8};

// 定義每個數字和字母對應的段位數據
int segmentMap[14][7] = {
    {1, 1, 1, 1, 1, 1, 0},  // 0
    {0, 1, 1, 0, 0, 0, 0},  // 1
    {1, 1, 0, 1, 1, 0, 1},  // 2
    {1, 1, 1, 1, 0, 0, 1},  // 3
    {0, 1, 1, 0, 0, 1, 1},  // 4
    {1, 0, 1, 1, 0, 1, 1},  // 5
    {1, 0, 1, 1, 1, 1, 1},  // 6
    {1, 1, 1, 0, 0, 0, 0},  // 7
    {1, 1, 1, 1, 1, 1, 1},  // 8
    {1, 1, 1, 1, 0, 1, 1},  // 9
    {1, 1, 1, 0, 1, 1, 1},  // A
    {0, 0, 1, 1, 1, 1, 1},  // B
    {1, 0, 0, 1, 1, 1, 0},  // C
    {0, 1, 1, 1, 1, 0, 1}   // D
};

// 儲存上一次接收的字符，初始為無效值
char lastDisplayedChar = '\0';

void setup() {
    // 初始化 7 段顯示器的引腳為輸出模式
    for (int i = 0; i < 7; i++) {
        pinMode(segPins[i], OUTPUT);
    }

    // 設置串口通信
    Serial.begin(9600);
}

// 顯示字符的函數
void displayChar(char ch) {
    int index = -1;

    // 判斷是數字還是字母，並設定對應的索引
    if (ch >= '0' && ch <= '9') {
        index = ch - '0';
    } else if (ch >= 'A' && ch <= 'D') {
        index = ch - 'A' + 10;
    }

    // 如果找到對應的索引，則更新顯示
    if (index != -1) {
        for (int i = 0; i < 7; i++) {
            digitalWrite(segPins[i], segmentMap[index][i]);
        }
    }
}

void loop() {
    // 檢查是否有數據從串口傳入
    if (Serial.available()) {
        char receivedChar = Serial.read();  // 讀取接收到的字符

        // 如果接收到的新字符不同於上次顯示的字符，則更新顯示
        if (receivedChar != lastDisplayedChar) {
            displayChar(receivedChar);         // 顯示新字符
            lastDisplayedChar = receivedChar;  // 記錄當前顯示的字符
        }
    }
}
