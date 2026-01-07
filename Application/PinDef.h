#pragma once

#include "stm32f1xx_hal.h"


class PinDef{
public:
	GPIO_TypeDef *Port;
	uint16_t Pin;

	PinDef(GPIO_TypeDef *port, uint16_t pin):
	Port{port}, Pin{pin} {}
};
