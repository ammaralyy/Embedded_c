################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ADC_prog.c \
../Dio_Prog.c \
../EXTERNAL_INTRUPT_PROG.c \
../LED_proj.c \
../main.c 

OBJS += \
./ADC_prog.o \
./Dio_Prog.o \
./EXTERNAL_INTRUPT_PROG.o \
./LED_proj.o \
./main.o 

C_DEPS += \
./ADC_prog.d \
./Dio_Prog.d \
./EXTERNAL_INTRUPT_PROG.d \
./LED_proj.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


