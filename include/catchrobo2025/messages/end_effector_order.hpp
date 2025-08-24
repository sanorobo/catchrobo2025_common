#pragma once

#include <cstdint>
#include <cstring>
#include <optional>

#include "can_message.hpp"

namespace catchrobo2025::messages {

struct EndEffectorOrder {
  static constexpr uint32_t ID = 0x011;

  uint8_t mode = 0b00000000;
  float z_pos = 0.0;
  float yaw_pos = 0.0;
};

inline CanMessage to_can_message(const EndEffectorOrder &end_effector_order) {
  CanMessage canmsg;
  canmsg.id = EndEffectorOrder::ID;
  canmsg.ide = false;
  canmsg.dlc = 7;
  std::memcpy(&canmsg.data[0], &end_effector_order.mode, sizeof(uint8_t));
  std::memcpy(&canmsg.data[1], &end_effector_order.z_pos, sizeof(float));
  int16_t yaw_i16 = end_effector_order.yaw_pos * 100;
  std::memcpy(&canmsg.data[5], &yaw_i16, sizeof(int16_t));
  return canmsg;
}

template <> std::optional<EndEffectorOrder> from_can_message(const CanMessage &msg) {
  if (msg.id != EndEffectorOrder::ID || msg.ide != false || msg.dlc != 7) {
    return std::nullopt;
  }
  EndEffectorOrder end_effector_order;
  std::memcpy(&end_effector_order.mode, &msg.data[0], sizeof(uint8_t));
  std::memcpy(&end_effector_order.z_pos, &msg.data[1], sizeof(float));
  int16_t yaw_i16;
  std::memcpy(&yaw_i16, &msg.data[5], sizeof(int16_t));
  end_effector_order.yaw_pos = yaw_i16 / 100.0f;
  // ここで任意のアサーションを追加して、失敗したらstd::nulloptを返すとかするとより安全
  return end_effector_order;
}

} // namespace catchrobo2025::messages