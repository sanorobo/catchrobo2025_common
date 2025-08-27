#pragma once

#include <array>
#include <cstdint>
#include <cstring>

namespace catchrobo2025::msg {

struct Localization {
  float x;
  float y;

  std::array<uint8_t, 8> serialize() const {
    std::array<uint8_t, 8> data{};
    std::memcpy(&data[0], &x, sizeof(float));
    std::memcpy(&data[4], &y, sizeof(float));
    return data;
  }

  static inline Localization deserialize(const std::array<uint8_t, 8> &data) {
    Localization localization{};
    std::memcpy(&localization.x, &data[0], sizeof(float));
    std::memcpy(&localization.y, &data[4], sizeof(float));
    return localization;
  }
};

} // namespace catchrobo2025::msg