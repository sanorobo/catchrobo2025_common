#pragma once

#include <cstddef>
#include <cstdint>
#include <exception>
#include <optional>

#include <halx/core.hpp>
#include <halx/peripheral/can.hpp>

namespace catchrobo2025::can {

template <uint32_t Id, class T> class Subscription {
public:
  Subscription(halx::peripheral::CanBase &can, uint32_t timeout = 1000) : can_{can}, timeout_{timeout} {
    auto filter_index = can_.attach_rx_queue({Id, Id, false}, rx_queue_);
    if (!filter_index) {
      std::terminate();
    }
    filter_index_ = *filter_index;
  }

  ~Subscription() { can_.detach_rx_filter(filter_index_); }

  std::optional<T> receive() {
    while (auto msg = rx_queue_.pop(0)) {
      msg_ = T::deserialize(msg->data);
      last_received_ = halx::core::get_tick();
    }
    if (static_cast<uint32_t>(halx::core::get_tick() - last_received_) > timeout_) {
      return std::nullopt;
    }
    return msg_;
  }

private:
  halx::peripheral::CanBase &can_;
  halx::core::RingBuffer<halx::peripheral::CanMessage> rx_queue_{64};
  size_t filter_index_;
  uint32_t timeout_;

  std::optional<T> msg_;
  uint32_t last_received_ = 0;
};

} // namespace catchrobo2025::can