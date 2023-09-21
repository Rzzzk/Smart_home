################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SRV/src/EEPROM_serv.c 

OBJS += \
./SRV/src/EEPROM_serv.o 

C_DEPS += \
./SRV/src/EEPROM_serv.d 


# Each subdirectory must supply rules for building sources it contributes
SRV/src/%.o: ../SRV/src/%.c SRV/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\COURCES\CAT\final project\SmartHomeProject\LIB" -I"D:\COURCES\CAT\final project\SmartHomeProject\MCAL\include" -I"D:\COURCES\CAT\final project\SmartHomeProject\HAL\include" -I"D:\COURCES\CAT\final project\SmartHomeProject\SRV\inc" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


