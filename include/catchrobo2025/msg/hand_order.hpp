#pragma once

#include <cstdint>

namespace catchrobo2025::msg {

enum class HandOrder : uint8_t {
  START = 0b00000001,
  IDLE = 0b00000010,
  ESCAPE = 0b00000100,
  POS0 = 0b00001000,
  POS1 = 0b00010000,
  POS2 = 0b00100000,
  POS3 = 0b01000000,
};

}