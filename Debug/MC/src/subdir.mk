################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MC/src/DIO_prog.c \
../MC/src/TWI_prog.c 

OBJS += \
./MC/src/DIO_prog.o \
./MC/src/TWI_prog.o 

C_DEPS += \
./MC/src/DIO_prog.d \
./MC/src/TWI_prog.d 


# Each subdirectory must supply rules for building sources it contributes
MC/src/%.o: ../MC/src/%.c MC/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\COURCES\CAT\final project\SmartHomeProject\LIB" -I"D:\COURCES\CAT\final project\SmartHomeProject\HAL\include" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


