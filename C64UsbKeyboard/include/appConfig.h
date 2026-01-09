#pragma once
#include "RawKey.h"
#include <stdint.h>
#include <array>


#define SERIAL_BAUDRATE 115200

#define NUM_ROWS 9
#define NUM_COLUMNS 9
#define NUM_RAW_KEYS 8

typedef std::array<uint8_t, NUM_ROWS> RowPinsArray;
typedef std::array<uint8_t, NUM_COLUMNS> ColPinsArray;
typedef std::array<RawKey, NUM_RAW_KEYS> RawKeysArray;
typedef std::array<uint8_t, NUM_RAW_KEYS> HidKeysArray;
typedef std::array<uint16_t, NUM_ROWS> RowStateArray;