#pragma once

#include <array>
#include <cstdint>
#include <cstring>

namespace catchrobo2025::msg {

struct EndEffectorModeTelemetry {
  uint8_t mode;

  std::array<uint8_t, 8> serialize() const {
    std::array<uint8_t, 8> data{};
    std::memcpy(&data[0], &mode, sizeof(uint8_t));
    return data;
  }

  static inline EndEffectorModeTelemetry deserialize(const std::array<uint8_t, 8> &data) {
    EndEffectorModeTelemetry end_effector_mode_telemetry{};
    std::memcpy(&end_effector_mode_telemetry.mode, &data[0], sizeof(uint8_t));
    return end_effector_mode_telemetry;
  }
};

} // namespace catchrobo2025::msg