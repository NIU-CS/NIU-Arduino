#define DECODE_NEC
#define IR_RECEIVE_PIN 0

#include <IRremote.hpp>

char led_num[10][8] = {
    {6, 2, 3, 4, 5, 6, 7},    // 0
    {2, 3, 4},                // 1
    {5, 2, 3, 5, 6, 8},       // 2
    {5, 2, 3, 4, 5, 8},       // 3
    {4, 3, 4, 7, 8},          // 4
    {5, 2, 4, 5, 7, 8},       // 5
    {6, 2, 4, 5, 6, 7, 8},    // 6
    {3, 2, 3, 4},             // 7
    {7, 2, 3, 4, 5, 6, 7, 8}, // 8
    {6, 2, 3, 4, 5, 7, 8}     // 9　
};

void led_dark() {
    for (int i = 2; i <= 8; i++) {
        digitalWrite(i, LOW);
    }
}

void setup() {
    Serial.begin(115200);
  #if defined(AVR_ATmega32U4) || defined(SERIAL_PORT_USBVIRTUAL) || defined(SERIAL_USB) || defined(ARDUINO_attiny3217)
    delay(1000);
#endif
    Serial.println(F("START IRremote example"));
    Serial.println(F("Enabling IRin..."));
    IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
    Serial.println(F("Ready to receive IR signals"));
    for (int i = 2; i <= 8; i++) {
        pinMode(i, OUTPUT);
    }
}

void loop() {
    int num, z;

    if (IrReceiver.decode()) {
        Serial.print(F("Received command: "));
        Serial.println(IrReceiver.decodedIRData.command, HEX);
        led_dark();
        switch (IrReceiver.decodedIRData.command) {
            case 0x10: num = 1; break;
            case 0x11: num = 2; break;
            case 0x12: num = 3; break;
            case 0x14: num = 4; break;
            case 0x15: num = 5; break;
            case 0x16: num = 6; break;
            case 0x17: num = 6; break;
            case 0x18: num = 7; break;
            case 0x19: num = 8; break;
            case 0x1A: num = 9; break;
            case 0xC: num = 0; break;
            default:
                Serial.println(F("Unknown command"));
                IrReceiver.resume();
                return;
        }

        z = led_num[num][0];
        for (int i = 1; i <= z; i++) {
            digitalWrite(led_num[num][i], HIGH);
        }

        IrReceiver.resume();
    }
    delay(100);
}
