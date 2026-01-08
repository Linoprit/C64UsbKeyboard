
// Refer to
// https://bytesnbits.co.uk/commodore-64-usb-keyboard/
// https://github.com/getis/c64-usb-keyboard

#include "MatrixDriver.h"
#include "RawKey.h"
#include "appConfig.h"
#include "stm32f103Config.h"
#include <Arduino.h>
#include "KeysToHid.h"


// ToDo:
// 8 / 8 = Restore = HID KEY_F11
// Missing: Menu = HID KEY_F12
// Missing: TapePlay = HID KEY_PAGEUP
// Modifier Keys (row/col):
// L-Shift (3/1),
// R-Shift (4/6),
// C= (5/0),
//


RowPinsArray rowPins = {row0, row1, row2, row3, row4, row5, row6, row7, row8};
ColPinsArray colPins = {columnA, columnB, columnC, columnD, columnE,
                        columnF, columnG, columnH, columnI};

MatrixDriver matrix = MatrixDriver(rowPins, colPins);
KeysToHid keysToHid;

void setup() {
  Serial.begin(SERIAL_BAUDRATE);
  USB_Begin();
  
  for (uint8_t colPin : colPins) {
    pinMode(colPin, INPUT_PULLUP);
  }

  // init rows as output and set high - inactive
  for (uint8_t rowPin : rowPins) {
    pinMode(rowPin, OUTPUT);
    digitalWrite(rowPin, HIGH);
  }

  Serial.println("finished setup");
  delay(10);
}

void loop() {

  matrix.cycle();

  if (matrix.hasChanged) {
    keysToHid.reportKeys(matrix.actKeys, matrix.scannedKeys);

    for (uint_fast8_t i = 0; i < matrix.scannedKeys; i++) {
      Serial.printf("row: %i / col: %i\n", matrix.actKeys[i].row,
                    matrix.actKeys[i].col);
    }
    if (matrix.scannedKeys == 0) {
      Serial.println("Released");
    }

    keysToHid.dumpKeyReport();
  }

  delay(1);
}

