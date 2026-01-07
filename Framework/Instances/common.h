#pragma once

#include "stm32f1xx_hal.h"
#include "cmsis_os.h"
#include "main.h"


// Cyclic task delays in [ms]
#define SYSTEM_TASK_DELAY 	 		100
#define APLICATION_TASK_DELAY		1000

// C interface
#ifdef __cplusplus
#define EXTERNC extern "C"
#else
#define EXTERNC
#endif

EXTERNC void common_init(void);

#undef EXTERNC
#ifdef __cplusplus

// put cpp includes here!!


// UART for debugging output
extern UART_HandleTypeDef huart1;
#define SERIAL_UART huart1


class Common
{
public:

  Common() {};
  virtual ~Common() {};

  static void init(void);
  static uint32_t get_tick(void) { return HAL_GetTick(); }
  static inline void delay(uint32_t delay)  { osDelay(delay); }
private:



};

#endif // C interface
