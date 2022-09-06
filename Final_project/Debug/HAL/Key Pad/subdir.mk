################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/Key\ Pad/KPD_PROGRAMME.c 

OBJS += \
./HAL/Key\ Pad/KPD_PROGRAMME.o 

C_DEPS += \
./HAL/Key\ Pad/KPD_PROGRAMME.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/Key\ Pad/KPD_PROGRAMME.o: ../HAL/Key\ Pad/KPD_PROGRAMME.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"HAL/Key Pad/KPD_PROGRAMME.d" -MT"HAL/Key\ Pad/KPD_PROGRAMME.d" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


