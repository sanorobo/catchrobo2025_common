#pragma once

#include <array>
#include <cstdint>
#include <cstring>

namespace kyourobo2026::msg {

struct ServoPosition {
  uint8_t id;
  float position;

  std::array<uint8_t, 8> serialize() const {
    std::array<uint8_t, 8> data{};
    std::memcpy(&data[0], &id, sizeof(uint8_t));
    std::memcpy(&data[2], &position, sizeof(float));
    return data;
  }

  static inline ServoPosition deserialize(const std::array<uint8_t, 8> &data) {
    ServoPosition servo_position{};
    std::memcpy(&servo_position.id, &data[0], sizeof(uint8_t));
    std::memcpy(&servo_position.position, &data[2], sizeof(float));
    return servo_position;
  }
};

} // namespace kyourobo2026::msg
