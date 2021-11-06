################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Dio_Prog.c \
../LED_proj.c \
../SPI_proj.c \
../UART_proj.c \
../main.c 

OBJS += \
./Dio_Prog.o \
./LED_proj.o \
./SPI_proj.o \
./UART_proj.o \
./main.o 

C_DEPS += \
./Dio_Prog.d \
./LED_proj.d \
./SPI_proj.d \
./UART_proj.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


