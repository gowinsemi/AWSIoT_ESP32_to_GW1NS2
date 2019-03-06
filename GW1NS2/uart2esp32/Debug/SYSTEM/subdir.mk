################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SYSTEM/system_gw1ns2c.c 

OBJS += \
./SYSTEM/system_gw1ns2c.o 

C_DEPS += \
./SYSTEM/system_gw1ns2c.d 


# Each subdirectory must supply rules for building sources it contributes
SYSTEM/%.o: ../SYSTEM/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -DUSE_STDPERIPH_DRIVER -I"C:\Users\Grant\Documents\Gowin\AWSIoT_ESP32_to_GW1NS2.git\GW1NS2\uart2esp32\CORE" -I"C:\Users\Grant\Documents\Gowin\AWSIoT_ESP32_to_GW1NS2.git\GW1NS2\uart2esp32\PERIPHER\Includes" -I"C:\Users\Grant\Documents\Gowin\AWSIoT_ESP32_to_GW1NS2.git\GW1NS2\uart2esp32\SYSTEM" -I"C:\Users\Grant\Documents\Gowin\AWSIoT_ESP32_to_GW1NS2.git\GW1NS2\uart2esp32\USER" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


