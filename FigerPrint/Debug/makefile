################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Software/MCAL/DIO/DIO_CODE/subdir.mk
-include Software/HAL/LCD/LCD_CODE/subdir.mk
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
FigerPrint.lss \

FLASH_IMAGE += \
FigerPrint.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: FigerPrint.elf secondary-outputs

# Tool invocations
FigerPrint.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,FigerPrint.map -mmcu=atmega32 -o "FigerPrint.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

FigerPrint.lss: FigerPrint.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S FigerPrint.elf  >"FigerPrint.lss"
	@echo 'Finished building: $@'
	@echo ' '

FigerPrint.hex: FigerPrint.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex FigerPrint.elf  "FigerPrint.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: FigerPrint.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 FigerPrint.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) FigerPrint.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
