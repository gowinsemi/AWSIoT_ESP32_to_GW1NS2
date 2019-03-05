# AWS IoT - GW1NS2 to ESP32 Example

### Software Installation Instructions for Arduino IDE and ESP32:

1. https://www.arduino.cc/en/Main/Software
2. `File > Preferences > Additional Board Manager URLs` and add `https://dl.espressif.com/dl/package_esp32_index.json`
3. `Tools > Board > Boards Manager… > ESP32 by Espressif Systems`
4. `Tools > Board > ESP32 Dev Module`
5. You can test setup by:
    1. Plugging in board > `Examples > WiFi > WiFiScan`
    2. `Tools > Port > Select COM port for board`
    3. `Tools > Serial Monitor > Select 115200 Baud`
    4. Upload on Arduino IDE > IDE should connect to board > Durring "Connecting..." you may have to press boot button.
    5. After code loads you should see WiFi networks availible in COM port.



### subPubTest

The subPubTest example is the same Hornbill AWS IoT for ESP32 example, but SSID, AWS Server, Topic and Certs can now be entered via terminal window.

Things to know:

1. Change partition scheme since certs and login info will be stored in RAM.   `Tools > Partition Scheme > No OTA (Large App)`

2. #define USERPARAMS in pubSubTest.ino sets the login information to be entered by the user via UART terminal

3. #define USERCERTS in AWS_IOT.c sets the certificate and key information to be entered by the user via UART terminal

4. Certificates and keys entered via terminal window need to be entered with "\n\ " at the end of each line.  This is the same format as aws_iot_certficates.c so you can copy and paste the certificates if entered in this file, or add "\n\ " to the end of each line of the certificate/key.

   - Example:

     -----BEGIN CERTIFICATE-----\n\
     xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n\
     xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n\
     xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n\
     -----END CERTIFICATE-----\n






