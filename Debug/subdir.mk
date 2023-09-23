################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../main.c \
../uart.c 

OBJS += \
./main.o \
./uart.o 

C_DEPS += \
./main.d \
./uart.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"C:\Users\Hp\Desktop\repo_cat\Smart_home\LIB" -I"C:\Users\Hp\Desktop\repo_cat\Smart_home\MCAL\include" -I"C:\Users\Hp\Desktop\repo_cat\Smart_home\HAL\include" -I"C:\Users\Hp\Desktop\repo_cat\Smart_home\SRV\inc" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


