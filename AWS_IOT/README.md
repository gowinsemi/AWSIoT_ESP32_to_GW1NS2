# Arduino-esp32-aws-iot

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



### Modified subPubTest Example

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



### *Original Hornbill AWS IoT Example Readme.md*

Arduini ESP32 library for AWS IoT

Please make sure you have read the [getting started guide](https://aws.amazon.com/iot/getting-started/) before trying to do anyting with this template.

This template is based on and contains the code from the [aws-iot-device-sdk-embedded-C](https://github.com/aws/aws-iot-device-sdk-embedded-C) project with an ESP32 port. It may help to review that project before attempting to use this template.

Define the below parameters in the sketch:
```
WIFI_SSID
WIFI_PASSWORD
HOST_ADDRESS
CLIENT_ID
TOPIC_NAME
```


*Certificates*
```
  root-CA.crt
  certificate.pem.crt
  private.pem.key
```
Above certificates needs to be stored in the file aws_iot_certificates.c as arrays. Check the file for more information.

![](https://exploreembedded.com/wiki/images/b/b9/ESP32_AWS_IOT_Certificates.png)


Please check this tutorial for setting up [AWS IOT on Amazon] (https://www.exploreembedded.com/wiki/Secure_IOT_with_AWS_and_Hornbill_ESP32)

Follow this tutorial for using the [Arduio Esp32 AWS libaray] (https://exploreembedded.com/wiki/AWS_IOT_with_Arduino_ESP32)


