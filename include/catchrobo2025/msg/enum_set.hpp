#pragma once

#include <array>
#include <cstdint>
#include <cstring>
#include <type_traits>

namespace catchrobo2025::msg {

template <class T> class EnumSet {
public:
  EnumSet() = default;

  template <class... Args> EnumSet(Args... args) { (insert(args), ...); }

  void insert(T value) { enums_ |= std::to_underlying(value); }

  void erase(T value) { enums_ &= ~std::to_underlying(value); }

  bool contains(T value) const { return (enums_ & std::to_underlying(value)) != 0; }

  std::array<uint8_t, 8> serialize() const {
    std::array<uint8_t, 8> data{};
    std::memcpy(data.data(), &enums_, sizeof(enums_));
    return data;
  }

  static inline EnumSet<T> deserialize(const std::array<uint8_t, 8> &data) {
    EnumSet<T> enum_set{};
    std::memcpy(&enum_set.enums_, data.data(), sizeof(enum_set.enums_));
    return enum_set;
  }

private:
  std::underlying_type_t<T> enums_ = 0;
};

} // namespace catchrobo2025::msg