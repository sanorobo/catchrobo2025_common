#pragma once

#include <cstdint>

namespace catchrobo2025::msg {

enum class ControlMode : uint8_t {
  CALIBRATION = 0b00000001,
  RED_ZONE = 0b10000000,
};

}