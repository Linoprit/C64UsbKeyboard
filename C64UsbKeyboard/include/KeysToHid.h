/*
  This is a derivative of Arduinos Keyboard.h, originally by Peter Barrett
*/

#pragma once

#include "HID.h"
#include "appConfig.h"

// Low level key report: up to 6 keys and shift, ctrl etc at once
typedef struct
{
  uint8_t modifiers;
  uint8_t reserved;
  uint8_t keys[6];
} KeyReport;

class KeysToHid
{
private:
  KeyReport _keyReport;
  void sendReport(KeyReport* keys);

public:
  KeysToHid(void);
  void reportKeys(RawKeysArray rawKeys, uint8_t scannedKeys);

  void begin();
  void end(void);

  uint8_t rawToHid(RawKey rawKey);
  bool addIfModifier(uint8_t hidCode);
  void releaseAll(void);
  void dumpKeyReport();
};

