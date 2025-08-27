#pragma once

#include <array>
#include <cstdint>
#include <cstring>

namespace catchrobo2025::msg {

struct MainArmModeTelemetry {
  uint8_t mode = 0b00000000;

  std::array<uint8_t, 8> serialize() const {
    std::array<uint8_t, 8> data{};
    std::memcpy(&data[0], &mode, sizeof(uint8_t));
    return data;
  }

  static inline MainArmModeTelemetry deserialize(const std::array<uint8_t, 8> &data) {
    MainArmModeTelemetry main_arm_mode_telemetry;
    std::memcpy(&main_arm_mode_telemetry.mode, &data[0], sizeof(uint8_t));
    return main_arm_mode_telemetry;
  }
};

} // namespace catchrobo2025::msg