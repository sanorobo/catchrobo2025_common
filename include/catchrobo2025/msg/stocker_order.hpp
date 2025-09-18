#pragma once

#include <cstdint>

namespace catchrobo2025::msg {

enum class StockerOrder : uint8_t {
  HOMING = 10,
  STOCK_1 = 11,
  STOCK_2 = 12,
  STOCK_3 = 13,
  STOCK_4 = 14,
  STOCK_5 = 15,
  STOCK_6 = 16,
  AVOID = 17,
  VIBRATION = 18,
};

}
