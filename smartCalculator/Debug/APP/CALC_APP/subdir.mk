################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../APP/CALC_APP/CALC_APP_prog.c 

OBJS += \
./APP/CALC_APP/CALC_APP_prog.o 

C_DEPS += \
./APP/CALC_APP/CALC_APP_prog.d 


# Each subdirectory must supply rules for building sources it contributes
APP/CALC_APP/%.o: ../APP/CALC_APP/%.c APP/CALC_APP/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


