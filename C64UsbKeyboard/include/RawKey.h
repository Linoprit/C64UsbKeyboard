#pragma once

#include <stdint.h>

class RawKey {
public:
  int16_t row = -1;
  int16_t col = -1;

  RawKey(){};
  RawKey(int16_t row_, int16_t col_) {
    row = row_;
    col = col_;
  }
  bool isNone() { return (row < 0) || (col < 0); }
};

bool operator==(const RawKey &lhs, const RawKey &rhs);