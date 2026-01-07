/*
 * MasterSerialTask.cpp
 *
 *  Created on: 02.02.2019
 *      Author: harald
 */
//
//#include <Instances/config.h>
//#include "../Application/ThetaSensors/ID_Table.h"
//#include "../Tasks/nRF24Task.h"
//#include <System/CommandLine/CommandLine.h>
//#include <System/OsHelpers.h>
//#include <Tasks/masterSerialTask.h>
//#include <Devices/at24c256/at24c256/AT24C256.h>
//
//#include <Sockets/CrcSocket.h>

#include "main.h"
#include "cmsis_os.h"
#include "stm32f1xx_hal.h"
#include "stm32f1xx_hal_uart.h"
#include "systemTask.h"
#include "System/serialPrintf.h"

void initCommandLine(void){
//	cLine::CommandLine::instance().init();
//	OsHelpers::delay(500);
//	cLine::CommandLine::instance().splash();
//	tx_cycle();
//	OsHelpers::delay(500);
}

void masterSerialTask(void const *argument) {
	//UNUSED(argument);

	initCommandLine();
	//HAL_UART_RxCpltCallback(&SERIAL_UART); // init serial reception mechanism

	for (;;) {
//		HAL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin);
		tx_cycle();
		osDelay(100);

//		cLine::CommandLine::instance().cycle();

	}
}


