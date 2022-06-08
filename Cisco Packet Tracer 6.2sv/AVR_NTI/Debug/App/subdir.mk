################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../App/main.c 

OBJS += \
./App/main.o 

C_DEPS += \
./App/main.d 


# Each subdirectory must supply rules for building sources it contributes
App/%.o: ../App/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"C:\Users\DELL\AVR_NTI\App" -I"C:\Users\DELL\AVR_NTI\Hal\Buzzer" -I"C:\Users\DELL\AVR_NTI\Hal\Led" -I"C:\Users\DELL\AVR_NTI\App\Library" -I"C:\Users\DELL\AVR_NTI\Hal" -I"C:\Users\DELL\AVR_NTI\Mcal" -I"C:\Users\DELL\AVR_NTI\Mcal\DIO" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


