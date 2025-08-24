#pragma once

#include <cstdint>
#include <cstring>
#include <optional>

#include "can_message.hpp"

namespace catchrobo2025::messages {

struct ModeOrder {
  static constexpr uint32_t ID = 0x0F0;

  uint8_t mode = 0b00000000;
};

inline CanMessage to_can_message(const ModeOrder &mode_order) {
  CanMessage msg;
  msg.id = ModeOrder::ID;
  msg.ide = false;
  msg.dlc = 1;
  std::memcpy(&msg.data[0], &mode_order.mode, sizeof(uint8_t));
  return msg;
}

template <> std::optional<ModeOrder> from_can_message(const CanMessage &msg) {
  if (msg.id != ModeOrder::ID || msg.ide != false || msg.dlc != 1) {
    return std::nullopt;
  }
  ModeOrder mode_order;
  std::memcpy(&mode_order.mode, &msg.data[0], sizeof(uint8_t));
  return mode_order;
}

} // namespace catchrobo2025::messages