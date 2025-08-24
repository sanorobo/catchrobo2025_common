#pragma once

#include <cstdint>
#include <cstring>
#include <optional>

#include "can_message.hpp"

namespace catchrobo2025::messages {

struct EndEffectorModeTelemetry {
  static constexpr uint32_t ID = 0x100;

  uint8_t mode;
};

inline CanMessage to_can_message(const EndEffectorModeTelemetry &end_effector_mode_telemetry) {
  CanMessage msg{};
  msg.id = EndEffectorModeTelemetry::ID;
  msg.ide = false;
  msg.dlc = 1;
  std::memcpy(&msg.data[0], &end_effector_mode_telemetry.mode, sizeof(uint8_t));
  return msg;
}

template <> std::optional<EndEffectorModeTelemetry> from_can_message(const CanMessage &msg) {
  if (msg.id != EndEffectorModeTelemetry::ID || msg.ide != false || msg.dlc != 1) {
    return std::nullopt;
  }
  EndEffectorModeTelemetry end_effector_mode_telemetry{};
  std::memcpy(&end_effector_mode_telemetry.mode, &msg.data[0], sizeof(uint8_t));
  return end_effector_mode_telemetry;
}

} // namespace catchrobo2025::messages