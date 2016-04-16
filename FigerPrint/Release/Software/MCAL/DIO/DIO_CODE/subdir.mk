################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Software/MCAL/DIO/DIO_CODE/DIO_prog.c 

OBJS += \
./Software/MCAL/DIO/DIO_CODE/DIO_prog.o 

C_DEPS += \
./Software/MCAL/DIO/DIO_CODE/DIO_prog.d 


# Each subdirectory must supply rules for building sources it contributes
Software/MCAL/DIO/DIO_CODE/%.o: ../Software/MCAL/DIO/DIO_CODE/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=4000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


