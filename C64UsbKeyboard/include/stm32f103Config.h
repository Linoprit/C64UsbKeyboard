#pragma once
#include <Arduino.h>
#include <stdint.h>

// 9 row drivers - outputs
const uint8_t row0 = PB9;  // 9;
const uint8_t row1 = PB8;  // 8;
const uint8_t row2 = PB7;  // 7;
const uint8_t row3 = PB6;  // 6;
const uint8_t row4 = PB5;  // 5;
const uint8_t row5 = PB4;  // 4;
const uint8_t row6 = PB3;  // 3;
const uint8_t row7 = PA15; // 2;
const uint8_t row8 = PB14; // 0;

// 9 column inputs - pulled high
const uint8_t columnA = PA0;  // 10;
const uint8_t columnB = PA1;  // 16;
const uint8_t columnC = PA2;  // 14;
const uint8_t columnD = PA3;  // 15;
const uint8_t columnE = PA4;  // 18;
const uint8_t columnF = PA5;  // 19;
const uint8_t columnG = PA6;  // 20;
const uint8_t columnH = PA7;  // 21;
const uint8_t columnI = PB13; // 1;
