#pragma once

#include <array>
#include <cstdint>
#include <cstring>

namespace kyourobo2026::msg {

struct FeetechPosition {
  uint8_t id;
  uint8_t direction;
  float position;

  std::array<uint8_t, 8> serialize() const {
    std::array<uint8_t, 8> data{};
    std::memcpy(&data[0], &id, sizeof(uint8_t));
    std::memcpy(&data[1], &direction, sizeof(uint8_t));
    std::memcpy(&data[2], &position, sizeof(float));
    return data;
  }

  static inline FeetechPosition deserialize(const std::array<uint8_t, 8> &data) {
    FeetechPosition feetech_position{};
    std::memcpy(&feetech_position.id, &data[0], sizeof(uint8_t));
    std::memcpy(&feetech_position.direction, &data[1], sizeof(uint8_t));
    std::memcpy(&feetech_position.position, &data[2], sizeof(float));
    return feetech_position;
  }
};

} // namespace kyourobo2026::msg
