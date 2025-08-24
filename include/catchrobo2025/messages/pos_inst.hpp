#pragma once

#include <cstdint>
#include <cstring>
#include <optional>

#include "can_message.hpp"

namespace catchrobo2025::messages {

struct PosInst {
  static constexpr uint32_t ID = 0x021;

  float x;
  float y;
};

inline CanMessage to_can_message(const PosInst &pos_inst) {
  CanMessage msg{};
  msg.id = PosInst::ID;
  msg.ide = false;
  msg.dlc = 8;
  std::memcpy(&msg.data[0], &pos_inst.x, sizeof(float));
  std::memcpy(&msg.data[4], &pos_inst.y, sizeof(float));
  return msg;
}

template <> std::optional<PosInst> from_can_message(const CanMessage &msg) {
  if (msg.id != PosInst::ID || msg.ide != false || msg.dlc != 8) {
    return std::nullopt;
  }
  PosInst pos_inst{};
  std::memcpy(&pos_inst.x, &msg.data[0], sizeof(float));
  std::memcpy(&pos_inst.y, &msg.data[4], sizeof(float));
  return pos_inst;
}

} // namespace catchrobo2025::messages