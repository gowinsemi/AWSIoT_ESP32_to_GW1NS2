# AWS IoT - GW1NS2 to ESP32 Example

Software Installation Instructions for Arduino IDE and ESP32:
1. https://www.arduino.cc/en/Main/Software
2. File > Preferences > Add `https://dl.espressif.com/dl/package_esp32_index.json` to "Additional Board Manager URLs"
3. Tools > Board > Boards Manager… > “ESP32 by Espressif Systems“
4. Tools > Board > ESP32 Dev Module
5. You can test setup by:
    1. Plugging in board > Examples > WiFi > WiFiScan
    2. Tools > Port > Select COM port for board
    3. Tools > Serial Monitor > Select 115200 Baud
    4. Upload on Arduino IDE > IDE should connect to board > Durring "Connecting..." you may have to press boot button.
    5. After code loads you should see WiFi networks availible in COM port.


