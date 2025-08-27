#pragma once

#include <cstdint>

#include <halx/core.hpp>
#include <halx/peripheral/can.hpp>

namespace catchrobo2025::can {

template <uint32_t Id, class T> class Publisher {
public:
  Publisher(halx::peripheral::CanBase &can) : can_{can} {}

  bool publish(const T &msg, uint32_t timeout = halx::core::MAX_DELAY) { return can_.transmit({Id, false, 8, msg.serialize()}, timeout); }

private:
  halx::peripheral::CanBase &can_;
};

} // namespace catchrobo2025::can