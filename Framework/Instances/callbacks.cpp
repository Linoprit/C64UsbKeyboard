/*
 * callbacks.c
 *
 *  Created on: 16.05.2016
 *      Author: harald
 */


#include <Instances/common.h>
#include "callbacks.h"
#include <main.h>
#include "stm32f1xx_hal.h"
//#include "Framework/libraries/Arduino/WString.h"
//#include "Framework/libraries/HelpersLib.h"
//#include <System/CommandLine/CommandLine.h>



/*void HAL_SYSTICK_Callback(void) {}*/

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	//UNUSED(GPIO_Pin);

//	if ((gpio_nRF24_callback != NULL) && (GPIO_Pin == Common::nRF24_gpio->get_IRQ_Pin() ))
//	{
//		gpio_nRF24_callback->ISR_callback_fcn();
//	}
//	else if ((button_callback != NULL) && (GPIO_Pin == BUTTON_1_Pin))
//	{
//		button_callback->ISR_callback_fcn();
//	}
}

uint8_t uart1Rx;
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
//	if (huart->Instance == USART1) {
//		cLine::CommandLine::instance().putChar(uart1Rx);
//		HAL_UART_Receive_IT(&SERIAL_UART, &uart1Rx, 1);
//	}

	//else if (huart->Instance == USART2) { 	}
	//else if (huart->Instance == USART3) {	}
}

//void HAL_UART_RxIdleCallback(UART_HandleTypeDef *huart)
//{
//  HAL_UART_RxCpltCallback(huart);
//}









