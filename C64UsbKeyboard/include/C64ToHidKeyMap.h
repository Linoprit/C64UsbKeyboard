#pragma once

#include "usb_hid_keys.h"
#include <Arduino.h>
#include <stdint.h>

// This matrix refers to the image "Commodore 64 Keyboard Matrix"
// at https://bytesnbits.co.uk/commodore-64-usb-keyboard/
//
// colum / row, i.e. key "R" is col 2 / row 1 => hid = C64Keymap[2][1]
// clang-format off
static const uint8_t C64Keymap[9][9] PROGMEM = {
// 0              1               2               3              4               5              6              7          8    
  {KEY_1,         KEY_GRAVE,      KEY_TAB,        KEY_ESC,       KEY_SPACE,      KEY_LEFTALT,   KEY_Q,         KEY_2,     KEY_NONE}, // 0 A
  {KEY_3,         KEY_W,          KEY_A,          KEY_LEFTSHIFT, KEY_Z,          KEY_S,         KEY_E,         KEY_4,     KEY_NONE}, // 1 B
  {KEY_5,         KEY_R,          KEY_D,          KEY_X,         KEY_C,          KEY_F,         KEY_T,         KEY_6,     KEY_NONE}, // 2 C
  {KEY_7,         KEY_Y,          KEY_G,          KEY_V,         KEY_B,          KEY_H,         KEY_U,         KEY_8,     KEY_NONE}, // 3 D
  {KEY_9,         KEY_I,          KEY_J,          KEY_N,         KEY_M,          KEY_K,         KEY_O,         KEY_0,     KEY_NONE}, // 4 E
  {KEY_EQUAL,     KEY_P,          KEY_L,          KEY_COMMA,     KEY_DOT,        KEY_SEMICOLON, KEY_LEFTBRACE, KEY_MINUS, KEY_NONE}, // 5 F
  {KEY_BACKSLASH, KEY_RIGHTBRACE, KEY_APOSTROPHE, KEY_SLASH,     KEY_RIGHTSHIFT, KEY_F10,       KEY_PAGEDOWN,  KEY_HOME,  KEY_NONE}, // 6 G
  {KEY_BACKSPACE, KEY_ENTER,      KEY_RIGHT,      KEY_DOWN,      KEY_F1,         KEY_F3,        KEY_F5,        KEY_F7,    KEY_NONE}, // 7 H
  {KEY_F12,       KEY_PAGEUP,     KEY_NONE,       KEY_NONE,      KEY_NONE,       KEY_NONE,      KEY_NONE,      KEY_NONE,  KEY_F11 }, // 8 I
    // clang-format on
};