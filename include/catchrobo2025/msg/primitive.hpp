#pragma once

#include <array>
#include <cstdint>
#include <cstring>

namespace catchrobo2025::msg {

template <class T> struct Primitive {
  T data;

  std::array<uint8_t, 8> serialize() const {
    std::array<uint8_t, 8> data{};
    std::memcpy(data.data(), &this->data, sizeof(T));
    return data;
  }

  static inline Primitive<T> deserialize(const std::array<uint8_t, 8> &data) {
    Primitive<T> primitive{};
    std::memcpy(&primitive.data, data.data(), sizeof(T));
    return primitive;
  }
};

} // namespace catchrobo2025::msg