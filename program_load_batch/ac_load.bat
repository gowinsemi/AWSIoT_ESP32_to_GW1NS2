::/****************************************Copyright (c)****************************************************
::**
::**                                 http://www.
::**
::**--------------File Info---------------------------------------------------------------------------------
::** File name:               gw_safe_chip_demo.bat
::** Last modified Date:      2019-03-29
::** Last Version:            1.0.0
::** Descriptions:
::**
::**--------------------------------------------------------------------------------------------------------
::** Created by:              feiyun.wu
::** Created date:            2019-03-29
::** Version:                 1.0.0
::** Descriptions:            
::**
::**--------------------------------------------------------------------------------------------------------
::** Modified by:
::** Modified date:
::** Version:
::** Descriptions:
::**
::*********************************************************************************************************/
@echo off

set com=COM17

set path=%cd%
set programmer_path=%path%\tools\programmer2.90306\programmer2\bin

echo.
echo com=%com%
echo programmer_path=%programmer_path%
echo path=%path%
echo.

echo.
echo 5. Load device_ac.bin
%programmer_path%\programmer_cli.exe --device GW1NS-2C --run 25 -a %path%\..\Certs\ESP32_BKP_1\provisioning_files\device_ac.bin
::echo programmer_cli.exe 25 errorlevel=%errorlevel%


echo.
echo Turn off the power,and turn on the power,the uart console will print the device_ac data.
echo Uart com=%com%, baudrate=115200

echo.
echo Finished.
echo.

pause


::/*********************************************************************************************************
::END FILE
::*********************************************************************************************************/