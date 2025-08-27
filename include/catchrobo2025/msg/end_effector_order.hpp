#pragma once

#include <array>
#include <cstdint>
#include <cstring>

namespace catchrobo2025::msg {

struct EndEffectorOrder {
  uint8_t mode = 0b00000000;
  float z_pos = 0.0;
  float yaw_pos = 0.0;

  std::array<uint8_t, 8> serialize() const {
    std::array<uint8_t, 8> data{};
    std::memcpy(&data[0], &mode, sizeof(uint8_t));
    std::memcpy(&data[1], &z_pos, sizeof(float));
    int16_t yaw_i16 = yaw_pos * 100;
    std::memcpy(&data[5], &yaw_i16, sizeof(int16_t));
    return data;
  }

  static inline EndEffectorOrder deserialize(const std::array<uint8_t, 8> &data) {
    EndEffectorOrder end_effector_order{};
    std::memcpy(&end_effector_order.mode, &data[0], sizeof(uint8_t));
    std::memcpy(&end_effector_order.z_pos, &data[1], sizeof(float));
    int16_t yaw_i16;
    std::memcpy(&yaw_i16, &data[5], sizeof(int16_t));
    end_effector_order.yaw_pos = yaw_i16 / 100.0f;
    return end_effector_order;
  }
};

} // namespace catchrobo2025::msg