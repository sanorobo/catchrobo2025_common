#pragma once

#include <cstdint>

namespace catchrobo2025::msg {

enum class StockerTelemetry : uint8_t {
  READY = 10,
  RUNNING = 11,
};

}
