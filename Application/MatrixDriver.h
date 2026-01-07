#pragma once

#include "RawKey.h"
#include <stdint.h>
#include <Instances/common.h>
#include <libraries/etl/array.h>
#include <PinDef.h>
#include <System/serialPrintf.h>


typedef etl::array<PinDef, NUM_ROWS> RowPinsArray;
typedef etl::array<PinDef, NUM_COLS> ColPinsArray;
typedef etl::array<RawKey, NUM_RAW_KEYS> RawKeysArray;
typedef etl::array<uint16_t, NUM_ROWS> RowStateArray;

class MatrixDriver {

public:
  RawKeysArray actKeys; // scanned keys as col / row
  uint8_t scannedKeys = 0; // count of scanned keys
  bool hasChanged = false; // keyboard state changed

  MatrixDriver(RowPinsArray &rowPins_, ColPinsArray &colPins_)
      : rowPins(rowPins_), colPins(colPins_) {}

  void cycle() {
    scannedKeys = scanMatrix();
    hasChanged = !(newState == oldState);
    if (hasChanged) {
      oldState = newState;
      rawKeys = actKeys;
    }
  }

  uint8_t scanMatrix() {
    uint_fast8_t actKeyPos = 0;

    actKeys.fill(RawKey());
    for (uint_fast8_t row = 0; row < rowPins.size(); row++) {
      activateRowLine(row);

      uint16_t actRowState = 0;
      for (uint_fast8_t col = 0; col < colPins.size(); col++) {
        uint16_t pinState =
        		!HAL_GPIO_ReadPin(
        				colPins[col].Port,
						colPins[col].Pin);
        		//!digitalRead(colPins[col]);
        if ((actKeyPos < actKeys.size()) && (pinState)) {
          actKeys[actKeyPos++] = RawKey(row, col);
        }
        actRowState |= pinState << col;
      }
      newState[row] = actRowState;
    }
    return actKeyPos;
  }

  void activateRowLine(uint_fast8_t rowNum) {
    for (uint_fast8_t row = 0; row < rowPins.size(); row++) {
      if (row == rowNum) {
        // turn on this row
        //digitalWrite(rowPins[row], LOW);
        HAL_GPIO_WritePin(
			rowPins[row].Port,
			rowPins[row].Pin,
			GPIO_PIN_RESET);

      } else {
        // turn off this row
        //digitalWrite(rowPins[row], HIGH);
        HAL_GPIO_WritePin(
			rowPins[row].Port,
			rowPins[row].Pin,
			GPIO_PIN_SET);
      }
    }
  }

private:
  RowStateArray newState;
  RowStateArray oldState;
  RawKeysArray rawKeys;
  RowPinsArray &rowPins;
  ColPinsArray &colPins;
};
