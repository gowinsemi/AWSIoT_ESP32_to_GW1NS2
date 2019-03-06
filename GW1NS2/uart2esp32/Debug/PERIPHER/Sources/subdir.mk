################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../PERIPHER/Sources/gw1ns2c_adc.c \
../PERIPHER/Sources/gw1ns2c_gpio.c \
../PERIPHER/Sources/gw1ns2c_imonitor.c \
../PERIPHER/Sources/gw1ns2c_lcd1602.c \
../PERIPHER/Sources/gw1ns2c_misc.c \
../PERIPHER/Sources/gw1ns2c_spi.c \
../PERIPHER/Sources/gw1ns2c_syscon.c \
../PERIPHER/Sources/gw1ns2c_timer.c \
../PERIPHER/Sources/gw1ns2c_uart.c \
../PERIPHER/Sources/gw1ns2c_wdog.c 

OBJS += \
./PERIPHER/Sources/gw1ns2c_adc.o \
./PERIPHER/Sources/gw1ns2c_gpio.o \
./PERIPHER/Sources/gw1ns2c_imonitor.o \
./PERIPHER/Sources/gw1ns2c_lcd1602.o \
./PERIPHER/Sources/gw1ns2c_misc.o \
./PERIPHER/Sources/gw1ns2c_spi.o \
./PERIPHER/Sources/gw1ns2c_syscon.o \
./PERIPHER/Sources/gw1ns2c_timer.o \
./PERIPHER/Sources/gw1ns2c_uart.o \
./PERIPHER/Sources/gw1ns2c_wdog.o 

C_DEPS += \
./PERIPHER/Sources/gw1ns2c_adc.d \
./PERIPHER/Sources/gw1ns2c_gpio.d \
./PERIPHER/Sources/gw1ns2c_imonitor.d \
./PERIPHER/Sources/gw1ns2c_lcd1602.d \
./PERIPHER/Sources/gw1ns2c_misc.d \
./PERIPHER/Sources/gw1ns2c_spi.d \
./PERIPHER/Sources/gw1ns2c_syscon.d \
./PERIPHER/Sources/gw1ns2c_timer.d \
./PERIPHER/Sources/gw1ns2c_uart.d \
./PERIPHER/Sources/gw1ns2c_wdog.d 


# Each subdirectory must supply rules for building sources it contributes
PERIPHER/Sources/%.o: ../PERIPHER/Sources/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -DUSE_STDPERIPH_DRIVER -I"C:\Users\Grant\Documents\Gowin\AWSIoT_ESP32_to_GW1NS2.git\GW1NS2\uart2esp32\CORE" -I"C:\Users\Grant\Documents\Gowin\AWSIoT_ESP32_to_GW1NS2.git\GW1NS2\uart2esp32\PERIPHER\Includes" -I"C:\Users\Grant\Documents\Gowin\AWSIoT_ESP32_to_GW1NS2.git\GW1NS2\uart2esp32\SYSTEM" -I"C:\Users\Grant\Documents\Gowin\AWSIoT_ESP32_to_GW1NS2.git\GW1NS2\uart2esp32\USER" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


