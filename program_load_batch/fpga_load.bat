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

::echo.
::echo 0. Erase mcu flash
::%programmer_path%\programmer_cli.exe --run 21 --device GW1NS-2C
::echo programmer_cli.exe 21 errorlevel=%errorlevel%
::pause

echo.
echo 1. Load safe_chip.fs
%programmer_path%\programmer_cli.exe --device GW1NS-2C --run 6 -f %path%\..\GW1NS2\fpga\impl\pnr\gowin_empu.fs
::echo programmer_cli.exe 6 errorlevel=%errorlevel%


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
