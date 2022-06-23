################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Mcal/Timer/Timer_Prog.c 

OBJS += \
./Mcal/Timer/Timer_Prog.o 

C_DEPS += \
./Mcal/Timer/Timer_Prog.d 


# Each subdirectory must supply rules for building sources it contributes
Mcal/Timer/%.o: ../Mcal/Timer/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"C:\Users\musta\NTIavr\App" -I"C:\Users\musta\NTIavr\Mcal\GIE" -I"C:\Users\musta\NTIavr\Mcal\Timer" -I"C:\Users\musta\NTIavr\Mcal\ADC" -I"C:\Users\musta\NTIavr\Mcal\ExtInt" -I"C:\Users\musta\NTIavr\Hal\KeyPad" -I"C:\Users\musta\NTIavr\Hal\LCD" -I"C:\Users\musta\NTIavr\Hal\PushButton" -I"C:\Users\musta\NTIavr\App\Library" -I"C:\Users\musta\NTIavr\Hal" -I"C:\Users\musta\NTIavr\Hal\Buzzer" -I"C:\Users\musta\NTIavr\Hal\Led" -I"C:\Users\musta\NTIavr\Hal\Relay" -I"C:\Users\musta\NTIavr\Hal\SSD" -I"C:\Users\musta\NTIavr\Mcal" -I"C:\Users\musta\NTIavr\Mcal\Dio" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


