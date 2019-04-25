################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../PERIPHER/Sources/gw1ns2k_adc.c \
../PERIPHER/Sources/gw1ns2k_gpio.c \
../PERIPHER/Sources/gw1ns2k_i2c.c \
../PERIPHER/Sources/gw1ns2k_imonitor.c \
../PERIPHER/Sources/gw1ns2k_lcd1602.c \
../PERIPHER/Sources/gw1ns2k_misc.c \
../PERIPHER/Sources/gw1ns2k_spi.c \
../PERIPHER/Sources/gw1ns2k_syscon.c \
../PERIPHER/Sources/gw1ns2k_timer.c \
../PERIPHER/Sources/gw1ns2k_typec.c \
../PERIPHER/Sources/gw1ns2k_uart.c \
../PERIPHER/Sources/gw1ns2k_wdog.c 

OBJS += \
./PERIPHER/Sources/gw1ns2k_adc.o \
./PERIPHER/Sources/gw1ns2k_gpio.o \
./PERIPHER/Sources/gw1ns2k_i2c.o \
./PERIPHER/Sources/gw1ns2k_imonitor.o \
./PERIPHER/Sources/gw1ns2k_lcd1602.o \
./PERIPHER/Sources/gw1ns2k_misc.o \
./PERIPHER/Sources/gw1ns2k_spi.o \
./PERIPHER/Sources/gw1ns2k_syscon.o \
./PERIPHER/Sources/gw1ns2k_timer.o \
./PERIPHER/Sources/gw1ns2k_typec.o \
./PERIPHER/Sources/gw1ns2k_uart.o \
./PERIPHER/Sources/gw1ns2k_wdog.o 

C_DEPS += \
./PERIPHER/Sources/gw1ns2k_adc.d \
./PERIPHER/Sources/gw1ns2k_gpio.d \
./PERIPHER/Sources/gw1ns2k_i2c.d \
./PERIPHER/Sources/gw1ns2k_imonitor.d \
./PERIPHER/Sources/gw1ns2k_lcd1602.d \
./PERIPHER/Sources/gw1ns2k_misc.d \
./PERIPHER/Sources/gw1ns2k_spi.d \
./PERIPHER/Sources/gw1ns2k_syscon.d \
./PERIPHER/Sources/gw1ns2k_timer.d \
./PERIPHER/Sources/gw1ns2k_typec.d \
./PERIPHER/Sources/gw1ns2k_uart.d \
./PERIPHER/Sources/gw1ns2k_wdog.d 


# Each subdirectory must supply rules for building sources it contributes
PERIPHER/Sources/%.o: ../PERIPHER/Sources/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -DUSE_STDPERIPH_DRIVER -I"C:\Users\Grant\Documents\Gowin\AWSIoT_ESP32_to_GW1NS2\trunk\GW1NS2\uart2esp32\CORE" -I"C:\Users\Grant\Documents\Gowin\AWSIoT_ESP32_to_GW1NS2\trunk\GW1NS2\uart2esp32\PERIPHER\Includes" -I"C:\Users\Grant\Documents\Gowin\AWSIoT_ESP32_to_GW1NS2\trunk\GW1NS2\uart2esp32\STARTUP" -I"C:\Users\Grant\Documents\Gowin\AWSIoT_ESP32_to_GW1NS2\trunk\GW1NS2\uart2esp32\SYSTEM" -I"C:\Users\Grant\Documents\Gowin\AWSIoT_ESP32_to_GW1NS2\trunk\GW1NS2\uart2esp32\USER" -I"C:\Users\Grant\Documents\Gowin\AWSIoT_ESP32_to_GW1NS2\trunk\GW1NS2\uart2esp32\broadkey\include" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


