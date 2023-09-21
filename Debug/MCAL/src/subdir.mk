################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/src/DIO_prog.c \
../MCAL/src/TWI_prog.c 

OBJS += \
./MCAL/src/DIO_prog.o \
./MCAL/src/TWI_prog.o 

C_DEPS += \
./MCAL/src/DIO_prog.d \
./MCAL/src/TWI_prog.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/src/%.o: ../MCAL/src/%.c MCAL/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\COURCES\CAT\final project\SmartHomeProject\LIB" -I"D:\COURCES\CAT\final project\SmartHomeProject\MCAL\include" -I"D:\COURCES\CAT\final project\SmartHomeProject\HAL\include" -I"D:\COURCES\CAT\final project\SmartHomeProject\SRV\inc" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


