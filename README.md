# AWS IoT - GW1NS2 to ESP32 Example



## Project Information

This project provides a basic example of how to connect the Gowin DK-START-GW1NS2 Development Board to AWS IoT via ESP32 WiFi Module.  Demo lights up one of 4 LEDs on each DK-START-GW1NS2 board connected to the cloud.  Push button "KEY1" can be pressed on any of the DK-START boards to change the LED that is on for all boards.

- The ESP32 program requests information to connect to a WiFi network and to the AWS IoT MQTT broker via UART.
- The Cortex M3 on the GW1NS2 SoC FPGA responds to the information requests appropriately.

![block_diagram](./doc_info/block_diagram.bmp)

​			Note - the voltage translator in the above picture is no longer required.*

### Install GNU MCU Eclipse

1. Obtain Gowin's GNU MCU Eclipse software package
   1. Extract `eclipse_tools > installer > jdk*.exe` to install Java SE Development Kit (use default settings)
   2. Test installation by opening command line and entering `java -version`
   3. `eclipse_tools > installer > Setup_JLink*.exe` to install debugger (use defaults)
2. Open Eclipse and set up project for Cortex M3
   1. Go to properties for the  `eclipse_tools_*` folder and uncheck `Read-only`
   2. Open `*\eclipse_tools_*\eclipse_tools_*\eclipse_tools\eclipse\eclipse.exe`
   3. Follow RN519 - MCU IDE Reference Manual for the rest of the instructions

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

## Firmware Setup and Loading

### Replace SSID and AWS Credentials

1. Open`\trunk\GW1NS2\uart2esp32\USER\main.c`

2. Replace the following lines with your SSID and AWS IoT credentials

   *const char SSID[]	=	"iPhone\n";*
   *const char PW[]		=	"iphone123\n";*
   *const char URL[]	=	"a2pb2f9st3ros6-ats.iot.us-east-2.amazonaws.com\n";*
   *const char THING[]	=	"ESP32\n";*
   *const char ROOTCA[]	=	"-----BEGIN CERTIFICATE-----\n\*
   *------------------------------------------------------------------------------------------------------------------\n\*
   *....*
   *-----END CERTIFICATE-----\r";*

   *const char DEVICECERT[]	=	"-----BEGIN CERTIFICATE-----\n\*
   *------------------------------------------------------------------------------------------------------------------\n\*
   *....*
   *-----END CERTIFICATE-----\r";*

   *const char DEVICEKEY []	=	"-----BEGIN RSA PRIVATE KEY-----\n\*
   *------------------------------------------------------------------------------------------------------------------\n\*
   *....*
   *-----END RSA PRIVATE KEY-----\r";*

3. Import uart2esp32 project --> Clean -- > Build

4. GW1NS2C firmware file will be uart.bin in the Debug folder

### Load GW1NS2C firmware files

1. FPGA --> `.\trunk\Firmware\GW1NS2_FPGA.fs` 
   1. Program in Gowin Programmer.  Choose Embedded Flash Mode
2. MCU --> `.\trunk\GW1NS2\uart2esp32\Debug\uart.bin`

### Load ESP32

1. Open `.\trunk\AWS_IOT\examples\pubSubTest\pubSubTest.ino` in Arduino IDE
2. Compile and Upload
   1. Note: press "Boot" push button on ESP32 while IDE says "Connecting..."
   2. Note: UART wires between ESP32 and GW1NS2C boards must be removed for ESP32 loading

## Connecting GW1NS2C DK-START and ESP32 Boards Together

![GW1NS2C_ESP32_Connectivity](.\doc_info\GW1NS2C_ESP32_Connectivity.jpg)

## Running the Demo

1. With both boards connected to each other and powered press the `EN` reset button on the ESP32 and the `RSET` on the GW1NS2C board.  Release the GW1NS2C reset first, followed by the ESP32 reset a second or more later.
2. You can monitor the status of the demo platform connecting to AWS through the ESP32 serial port using a terminal program like Realterm.
3. After the device is connected press `KEY1`.  A number from 1-4 will be incremented and sent to the cloud.  All connected devices including the device that had the key pressed will receive the new number from the broker.  The new LED will light corresponding to the number 1-4 received.

