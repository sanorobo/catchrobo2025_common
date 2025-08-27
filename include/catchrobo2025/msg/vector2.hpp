#pragma once

#include <array>
#include <cstdint>
#include <cstring>

namespace catchrobo2025::msg {

struct Vector2 {
  float x;
  float y;

  std::array<uint8_t, 8> serialize() const {
    std::array<uint8_t, 8> data{};
    std::memcpy(&data[0], &x, sizeof(float));
    std::memcpy(&data[4], &y, sizeof(float));
    return data;
  }

  static inline Vector2 deserialize(const std::array<uint8_t, 8> &data) {
    Vector2 vector2{};
    std::memcpy(&vector2.x, &data[0], sizeof(float));
    std::memcpy(&vector2.y, &data[4], sizeof(float));
    return vector2;
  }
};

} // namespace catchrobo2025::msg