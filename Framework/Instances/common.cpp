/*
 * Initclasses.cpp
 *
 *  Created on: 06.05.2016
 *      Author: harald
 */

#include <Instances/common.h>
#include "stm32f1xx_hal.h"
#include "main.h"
#include "callbacks.h"


// C interface
void common_init(void) {
	Common::init();
}

void Common::init() {
	// switch off LED
	HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_SET);

}

