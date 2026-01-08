#include "RawKey.h"


bool operator==(const RawKey &lhs, const RawKey &rhs) {
  return (lhs.col == rhs.col) && (lhs.row == rhs.col);
};