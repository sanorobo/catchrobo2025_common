#pragma once

#include <cstdint>
#include <cstring>
#include <optional>

#include "can_message.hpp"

namespace catchrobo2025::messages {

struct Localization {
  static constexpr uint32_t ID = 0x201;

  float x;
  float y;
};

inline CanMessage to_can_message(const Localization &localization) {
  CanMessage msg{};
  msg.id = Localization::ID;
  msg.ide = false;
  msg.dlc = 8;
  std::memcpy(&msg.data[0], &localization.x, sizeof(float));
  std::memcpy(&msg.data[4], &localization.y, sizeof(float));
  return msg;
}

template <> std::optional<Localization> from_can_message(const CanMessage &msg) {
  if (msg.id != Localization::ID || msg.ide != false || msg.dlc != 8) {
    return std::nullopt;
  }
  Localization localization{};
  std::memcpy(&localization.x, &msg.data[0], sizeof(float));
  std::memcpy(&localization.y, &msg.data[4], sizeof(float));
  return localization;
}

} // namespace catchrobo2025::messages