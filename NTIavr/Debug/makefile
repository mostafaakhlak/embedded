################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Mcal/ExtInt/subdir.mk
-include Mcal/Dio/subdir.mk
-include Mcal/ADC/subdir.mk
-include Hal/SSD/subdir.mk
-include Hal/Relay/subdir.mk
-include Hal/PushButton/subdir.mk
-include Hal/Led/subdir.mk
-include Hal/LCD/subdir.mk
-include Hal/KeyPad/subdir.mk
-include Hal/Buzzer/subdir.mk
-include App/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
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
LSS += \
NTIavr.lss \

FLASH_IMAGE += \
NTIavr.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: NTIavr.elf secondary-outputs

# Tool invocations
NTIavr.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,NTIavr.map -mmcu=atmega32 -o "NTIavr.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

NTIavr.lss: NTIavr.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S NTIavr.elf  >"NTIavr.lss"
	@echo 'Finished building: $@'
	@echo ' '

NTIavr.hex: NTIavr.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex NTIavr.elf  "NTIavr.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: NTIavr.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 NTIavr.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) NTIavr.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
