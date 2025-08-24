#pragma once

#include <cstdint>
#include <cstring>
#include <optional>

#include "can_message.hpp"

namespace catchrobo2025::messages {

struct MainArmModeTelemetry {
  static constexpr uint32_t ID = 0x200;

  uint8_t mode = 0b00000000;
};

inline CanMessage to_can_message(const MainArmModeTelemetry &main_arm_mode_telemetry) {
  CanMessage msg;
  msg.id = MainArmModeTelemetry::ID;
  msg.ide = false;
  msg.dlc = 1;
  std::memcpy(&msg.data[0], &main_arm_mode_telemetry.mode, sizeof(uint8_t));
  return msg;
}

template <> std::optional<MainArmModeTelemetry> from_can_message(const CanMessage &msg) {
  if (msg.id != MainArmModeTelemetry::ID || msg.ide != false || msg.dlc != 1) {
    return std::nullopt;
  }
  MainArmModeTelemetry main_arm_mode_telemetry;
  std::memcpy(&main_arm_mode_telemetry.mode, &msg.data[0], sizeof(uint8_t));
  return main_arm_mode_telemetry;
}

} // namespace catchrobo2025::messages