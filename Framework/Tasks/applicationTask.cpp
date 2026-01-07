#include <Instances/common.h>
#include "main.h"
#include "cmsis_os.h"
#include "stm32f1xx_hal.h"
#include "usbd_hid.h"
#include "applicationTask.h"
#include "System/serialPrintf.h"
#include <MatrixDriver.h>
#include <libraries/etl/array.h>

extern USBD_HandleTypeDef hUsbDeviceFS;

typedef struct {
	uint8_t MODIFIER;
	uint8_t RESERVED;
	uint8_t KEYCODE1;
	uint8_t KEYCODE2;
	uint8_t KEYCODE3;
	uint8_t KEYCODE4;
	uint8_t KEYCODE5;
	uint8_t KEYCODE6;
} subKeyBoard;

subKeyBoard keyBoardHIDsub = { 0, 0, 0, 0, 0, 0, 0, 0 };

// @formatter:off
RowPinsArray rowPins = {
		PinDef(Row0_GPIO_Port, Row0_Pin),
		PinDef(Row1_GPIO_Port, Row1_Pin),
		PinDef(Row2_GPIO_Port, Row2_Pin),
		PinDef(Row3_GPIO_Port, Row3_Pin),
		PinDef(Row4_GPIO_Port, Row4_Pin),
		PinDef(Row5_GPIO_Port, Row5_Pin),
		PinDef(Row6_GPIO_Port, Row6_Pin),
		PinDef(Row7_GPIO_Port, Row7_Pin),
		PinDef(Row8_GPIO_Port, Row8_Pin),
};

ColPinsArray colPins = {
		PinDef(ColA_GPIO_Port, ColA_Pin),
		PinDef(ColB_GPIO_Port, ColB_Pin),
		PinDef(ColC_GPIO_Port, ColC_Pin),
		PinDef(ColD_GPIO_Port, ColD_Pin),
		PinDef(ColE_GPIO_Port, ColE_Pin),
		PinDef(ColF_GPIO_Port, ColF_Pin),
		PinDef(ColG_GPIO_Port, ColG_Pin),
		PinDef(ColH_GPIO_Port, ColH_Pin),
		PinDef(ColI_GPIO_Port, ColI_Pin),
};
// @formatter:on

MatrixDriver matrix = MatrixDriver(rowPins, colPins);

void applicationTask(void const *argument) {

	// init rows as output and set high - inactive
	for (PinDef rowPin : rowPins) {
		HAL_GPIO_WritePin(rowPin.Port, rowPin.Pin, GPIO_PIN_SET);
	}

	tx_printf("finished setup\n");
	osDelay(10);

	for (;;) {

		matrix.cycle();

		if (matrix.hasChanged) {
			for (uint_fast8_t i = 0; i < matrix.scannedKeys; i++) {
				tx_printf("row: %i / col: %i\n", matrix.actKeys[i].row,
						matrix.actKeys[i].col);
			}
			if (matrix.scannedKeys == 0) {
				tx_printf("Released\n");
			}
		}
		osDelay(10);

		HAL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin);


		keyBoardHIDsub.MODIFIER = 0x02;  // To press shift key
		keyBoardHIDsub.KEYCODE1 = 0x04;  // Press A key
		keyBoardHIDsub.KEYCODE2 = 0x05;  // Press B key
		keyBoardHIDsub.KEYCODE3 = 0x06;  // Press C key
		USBD_HID_SendReport(&hUsbDeviceFS, (uint8_t*) &keyBoardHIDsub,
				sizeof(keyBoardHIDsub));
		osDelay(50); 		       // Press all key for 50 milliseconds
		keyBoardHIDsub.MODIFIER = 0x00;  // To release shift key
		keyBoardHIDsub.KEYCODE1 = 0x00;  // Release A key
		keyBoardHIDsub.KEYCODE2 = 0x00;  // Release B key
		keyBoardHIDsub.KEYCODE3 = 0x00;  // Release C key
		USBD_HID_SendReport(&hUsbDeviceFS, (uint8_t*) &keyBoardHIDsub,
				sizeof(keyBoardHIDsub));
		osDelay(APLICATION_TASK_DELAY);

	}
}

