/*
  This is a derivative of Arduinos Keyboard.h, originally by Peter Barrett
*/

#include "C64ToHidKeyMap.h"
#include "KeysToHid.h"
#include <string>

#if defined(_USING_HID)

const uint8_t _hidReportDescriptor[] PROGMEM = {

    //  Keyboard
    0x05, 0x01, // USAGE_PAGE (Generic Desktop)  // 47
    0x09, 0x06, // USAGE (Keyboard)
    0xa1, 0x01, // COLLECTION (Application)
    0x85, 0x02, //   REPORT_ID (2)
    0x05, 0x07, //   USAGE_PAGE (Keyboard)

    0x19, 0xe0, //   USAGE_MINIMUM (Keyboard LeftControl)
    0x29, 0xe7, //   USAGE_MAXIMUM (Keyboard Right GUI)
    0x15, 0x00, //   LOGICAL_MINIMUM (0)
    0x25, 0x01, //   LOGICAL_MAXIMUM (1)
    0x75, 0x01, //   REPORT_SIZE (1)

    0x95, 0x08, //   REPORT_COUNT (8)
    0x81, 0x02, //   INPUT (Data,Var,Abs)
    0x95, 0x01, //   REPORT_COUNT (1)
    0x75, 0x08, //   REPORT_SIZE (8)
    0x81, 0x03, //   INPUT (Cnst,Var,Abs)

    0x95, 0x06, //   REPORT_COUNT (6)
    0x75, 0x08, //   REPORT_SIZE (8)
    0x15, 0x00, //   LOGICAL_MINIMUM (0)
    0x25, 0x73, //   LOGICAL_MAXIMUM (115)
    0x05, 0x07, //   USAGE_PAGE (Keyboard)

    0x19, 0x00, //   USAGE_MINIMUM (Reserved (no event indicated))
    0x29, 0x73, //   USAGE_MAXIMUM (Keyboard Application)
    0x81, 0x00, //   INPUT (Data,Ary,Abs)
    0xc0,       // END_COLLECTION
};

KeysToHid::KeysToHid(void) {
  static HIDSubDescriptor node(_hidReportDescriptor,
                               sizeof(_hidReportDescriptor));
  HID().AppendDescriptor(&node);
}

void KeysToHid::sendReport(KeyReport *keys) {
  HID().SendReport(2, keys, sizeof(KeyReport));
}

void KeysToHid::reportKeys(RawKeysArray rawKeys, uint8_t scannedKeys) {
  HidKeysArray hidKeys;

  releaseAll();

  if (scannedKeys != 0) {
    for (uint_fast8_t i = 0; i < scannedKeys; i++) {
      RawKey rawKey = rawKeys[i];
      hidKeys[i] = rawToHid(rawKey);
    }

    if (shiftAndCursorActive(hidKeys, scannedKeys)) {
      writeCursorToReport(hidKeys, scannedKeys);
    } else {
      writeHidToReport(hidKeys, scannedKeys);
    }
  }

  sendReport(&_keyReport);
}

// Unfortunately the FPGA Companion OSD does not recognize Shift-Cursor keys. 
// So, if we detect Shift and Cursor down or right, we sent the corresponding
// HID-Key and ignore all other keys. 
void KeysToHid::writeCursorToReport(HidKeysArray hidKeys, uint8_t scannedKeys) {
  uint_fast8_t keySlot = 0;
  for (uint_fast8_t i = 0; i < scannedKeys; i++) {
    uint8_t hidCode = hidKeys[i];

    if (hidCode == KEY_RIGHT) {
      _keyReport.keys[keySlot++] = KEY_LEFT; 
    }
    if (hidCode == KEY_DOWN) {
      _keyReport.keys[keySlot++] = KEY_UP; 
    }
    if (keySlot > 5) { 
      break;
    }
  }
}

bool KeysToHid::shiftAndCursorActive(HidKeysArray hidKeys,
                                     uint8_t scannedKeys) {
  bool shiftFlag = false;
  bool cursorFlag = false;

  for (uint_fast8_t i = 0; i < scannedKeys; i++) {
    uint8_t hidCode = hidKeys[i];
    if ((hidCode == KEY_RIGHTSHIFT) || (hidCode == KEY_LEFTSHIFT)) {
      shiftFlag = true;
    }
    if ((hidCode == KEY_RIGHT) || (hidCode == KEY_DOWN)) {
      cursorFlag = true;
    }
    if (shiftFlag && cursorFlag) {
      return true;
    }
  }
  return false;
}

void KeysToHid::writeHidToReport(HidKeysArray hidKeys, uint8_t scannedKeys) {
  uint_fast8_t keySlot = 0;
  for (uint_fast8_t i = 0; i < scannedKeys; i++) {
    if (addIfModifier(hidKeys[i])) {
      continue;
    } else {
      _keyReport.keys[keySlot++] = hidKeys[i];
      // If we have more than 6 keys, we ignore the rest.
      if (keySlot > 5) {
        break;
      }
    }
  }
}

bool KeysToHid::addIfModifier(uint8_t hidCode) {
  if ((hidCode >= KEY_LEFTCTRL) && (hidCode <= KEY_RIGHTMETA)) {
    uint8_t maskedHid = (hidCode & 0x0f);
    uint8_t modifierCode = 1u << maskedHid;
    _keyReport.modifiers |= modifierCode;
    return true;
  }
  return false;
}

uint8_t KeysToHid::rawToHid(RawKey rawKey) {
  if (rawKey.isNone()) {
    return KEY_NONE;
  }
  return C64Keymap[rawKey.col][rawKey.row];
}

void KeysToHid::releaseAll(void) {
  _keyReport.keys[0] = 0;
  _keyReport.keys[1] = 0;
  _keyReport.keys[2] = 0;
  _keyReport.keys[3] = 0;
  _keyReport.keys[4] = 0;
  _keyReport.keys[5] = 0;
  _keyReport.modifiers = 0;
}

void KeysToHid::dumpKeyReport() {

  Serial.printf("Modifiers: %i ", _keyReport.modifiers);
  Serial.printf("Keys: ");
  for (uint_fast8_t i = 0; i < 6; i++) {
    Serial.printf("%i: 0x%x, ", i, _keyReport.keys[i]);
  }
  Serial.println();
}

#endif
