#pragma once

#include <array>
#include <cstdint>
#include <cstring>

namespace catchrobo2025::msg {

struct ModeOrder {
  uint8_t mode;

  std::array<uint8_t, 8> serialize() const {
    std::array<uint8_t, 8> data{};
    std::memcpy(&data[0], &mode, sizeof(uint8_t));
    return data;
  }

  static inline ModeOrder deserialize(const std::array<uint8_t, 8> &data) {
    ModeOrder mode_order{};
    std::memcpy(&mode_order.mode, &data[0], sizeof(uint8_t));
    return mode_order;
  }
};

} // namespace catchrobo2025::msg