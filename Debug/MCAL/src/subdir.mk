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
	avr-gcc -I"C:\Users\Hp\Desktop\repo_cat\Smart_home\LIB" -I"C:\Users\Hp\Desktop\repo_cat\Smart_home\MCAL\include" -I"C:\Users\Hp\Desktop\repo_cat\Smart_home\HAL\include" -I"C:\Users\Hp\Desktop\repo_cat\Smart_home\SRV\inc" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


