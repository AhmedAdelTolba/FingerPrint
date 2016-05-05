################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../headerfiles/DelayFiles/Delay_prog.c 

OBJS += \
./headerfiles/DelayFiles/Delay_prog.o 

C_DEPS += \
./headerfiles/DelayFiles/Delay_prog.d 


# Each subdirectory must supply rules for building sources it contributes
headerfiles/DelayFiles/%.o: ../headerfiles/DelayFiles/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=4000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


