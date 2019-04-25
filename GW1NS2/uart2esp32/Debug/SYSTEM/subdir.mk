################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SYSTEM/system_gw1ns2k.c 

OBJS += \
./SYSTEM/system_gw1ns2k.o 

C_DEPS += \
./SYSTEM/system_gw1ns2k.d 


# Each subdirectory must supply rules for building sources it contributes
SYSTEM/%.o: ../SYSTEM/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -DUSE_STDPERIPH_DRIVER -I"C:\Users\Grant\Documents\Gowin\AWSIoT_ESP32_to_GW1NS2\trunk\GW1NS2\uart2esp32\CORE" -I"C:\Users\Grant\Documents\Gowin\AWSIoT_ESP32_to_GW1NS2\trunk\GW1NS2\uart2esp32\PERIPHER\Includes" -I"C:\Users\Grant\Documents\Gowin\AWSIoT_ESP32_to_GW1NS2\trunk\GW1NS2\uart2esp32\STARTUP" -I"C:\Users\Grant\Documents\Gowin\AWSIoT_ESP32_to_GW1NS2\trunk\GW1NS2\uart2esp32\SYSTEM" -I"C:\Users\Grant\Documents\Gowin\AWSIoT_ESP32_to_GW1NS2\trunk\GW1NS2\uart2esp32\USER" -I"C:\Users\Grant\Documents\Gowin\AWSIoT_ESP32_to_GW1NS2\trunk\GW1NS2\uart2esp32\broadkey\include" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


