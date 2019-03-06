# AWS IoT - GW1NS2 to ESP32 Example



## Project Information

This project provides a basic example of how to connect the Gowin DK-START-GW1NS2 Development Board to AWS IoT via ESP32 WiFi Module.

- The ESP32 program requests information to connect to a WiFi network and to the AWS IoT MQTT broker via UART.
- The Cortex M3 on the GW1NS2 SoC FPGA responds to the information requests appropriately.

![block_diagram](./doc_info/block_diagram.bmp)

The GW1NS and ESP32 projects can be tested independently using a RS232 cable and a microUSB cable respectively.

Communication between the boards requires a voltage translator since the UART port of the GW1NS2 development board requires 5V and the ESP32 requires 3.3V.



#### *Note - I have still not properly tested board to board communication, because I do not have a 5V/3.3V voltage translator module handy.  Will test soon.*


