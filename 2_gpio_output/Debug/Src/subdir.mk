################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/main.c \
../Src/syscalls.c \
../Src/sysmem.c 

OBJS += \
./Src/main.o \
./Src/syscalls.o \
./Src/sysmem.o 

C_DEPS += \
./Src/main.d \
./Src/syscalls.d \
./Src/sysmem.d 


# Each subdirectory must supply rules for building sources it contributes
Src/main.o: ../Src/main.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F4 -DSTM32F411RETx -DDEBUG -DSTM32F411xE -c -I../Inc -I"C:/Users/Israel/Documents/STM32F4-BareMetal_Workspace/2_gpio_output/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/Israel/Documents/STM32F4-BareMetal_Workspace/2_gpio_output/Drivers/CMSIS/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/main.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Src/syscalls.o: ../Src/syscalls.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F4 -DSTM32F411RETx -DDEBUG -DSTM32F411xE -c -I../Inc -I"C:/Users/Israel/Documents/STM32F4-BareMetal_Workspace/2_gpio_output/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/Israel/Documents/STM32F4-BareMetal_Workspace/2_gpio_output/Drivers/CMSIS/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/syscalls.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Src/sysmem.o: ../Src/sysmem.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F4 -DSTM32F411RETx -DDEBUG -DSTM32F411xE -c -I../Inc -I"C:/Users/Israel/Documents/STM32F4-BareMetal_Workspace/2_gpio_output/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/Israel/Documents/STM32F4-BareMetal_Workspace/2_gpio_output/Drivers/CMSIS/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/sysmem.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

