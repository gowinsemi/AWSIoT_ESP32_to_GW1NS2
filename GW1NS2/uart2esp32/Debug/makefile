################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include broadkey/src/subdir.mk
-include USER/subdir.mk
-include SYSTEM/subdir.mk
-include STARTUP/subdir.mk
-include PERIPHER/Sources/subdir.mk
-include CORE/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
SECONDARY_FLASH += \
awsIoT_BKP.bin \

SECONDARY_SIZE += \
awsIoT_BKP.siz \


# All Target
all: awsIoT_BKP.elf secondary-outputs

# Tool invocations
awsIoT_BKP.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: Cross ARM GNU C Linker'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -T "C:\Users\Grant\Documents\Gowin\AWSIoT_ESP32_to_GW1NS2\trunk\GW1NS2\uart2esp32\gw1ns2k_flash.ld" -Xlinker --gc-sections -L"C:\Users\Grant\Documents\Gowin\AWSIoT_ESP32_to_GW1NS2\trunk\GW1NS2\uart2esp32\broadkey\lib" -Wl,-Map,"awsIoT_BKP.map" -o "awsIoT_BKP.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

awsIoT_BKP.bin: awsIoT_BKP.elf
	@echo 'Invoking: Cross ARM GNU Create Flash Image'
	arm-none-eabi-objcopy -O binary "awsIoT_BKP.elf"  "awsIoT_BKP.bin"
	@echo 'Finished building: $@'
	@echo ' '

awsIoT_BKP.siz: awsIoT_BKP.elf
	@echo 'Invoking: Cross ARM GNU Print Size'
	arm-none-eabi-size --format=berkeley "awsIoT_BKP.elf"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(SECONDARY_FLASH)$(SECONDARY_SIZE)$(ASM_DEPS)$(S_UPPER_DEPS)$(C_DEPS) awsIoT_BKP.elf
	-@echo ' '

secondary-outputs: $(SECONDARY_FLASH) $(SECONDARY_SIZE)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
