#pragma once

#include <cstdint>

namespace catchrobo2025::msg {

enum class HandTelemetry : uint8_t {
  READY = 0b00000001,
  COMPLETE = 0b00000010,
};

}