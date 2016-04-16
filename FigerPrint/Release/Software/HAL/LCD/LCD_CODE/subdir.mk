################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Software/HAL/LCD/LCD_CODE/LCD_Prog.c 

OBJS += \
./Software/HAL/LCD/LCD_CODE/LCD_Prog.o 

C_DEPS += \
./Software/HAL/LCD/LCD_CODE/LCD_Prog.d 


# Each subdirectory must supply rules for building sources it contributes
Software/HAL/LCD/LCD_CODE/%.o: ../Software/HAL/LCD/LCD_CODE/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=4000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


