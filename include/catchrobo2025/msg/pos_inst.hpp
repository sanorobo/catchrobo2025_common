#pragma once

#include <array>
#include <cstdint>
#include <cstring>

namespace catchrobo2025::msg {

struct PosInst {
  float x;
  float y;

  std::array<uint8_t, 8> serialize() const {
    std::array<uint8_t, 8> data{};
    std::memcpy(&data[0], &x, sizeof(float));
    std::memcpy(&data[4], &y, sizeof(float));
    return data;
  }

  static inline PosInst deserialize(const std::array<uint8_t, 8> &data) {
    PosInst pos_inst{};
    std::memcpy(&pos_inst.x, &data[0], sizeof(float));
    std::memcpy(&pos_inst.y, &data[4], sizeof(float));
    return pos_inst;
  }
};

} // namespace catchrobo2025::msg