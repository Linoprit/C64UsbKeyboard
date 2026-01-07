#!/usr/bin/env bash
cd "$(dirname "$0")"

#cp ./doc/resources/stm32f1xx_hal_uart.c ./Drivers/STM32F1xx_HAL_Driver/Src/
#cp ./doc/resources/stm32f1xx_hal_uart.h ./Drivers/STM32F1xx_HAL_Driver/Inc/
cp ./doc/resources/usbd_hid.h ./Middlewares/ST/STM32_USB_Device_Library/Class/HID/Inc/
cp ./doc/resources/usbd_hid.c ./Middlewares/ST/STM32_USB_Device_Library/Class/HID/Src/
