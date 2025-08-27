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
  Subscription(halx::peripheral::CanBase &can) : can_{can} {
    auto filter_index = can_.attach_rx_queue({Id, Id, false}, rx_queue_);
    if (!filter_index) {
      std::terminate();
    }
    filter_index_ = *filter_index;
  }

  ~Subscription() { can_.detach_rx_filter(filter_index_); }

  std::optional<T> receive(uint32_t timeout = 0) {
    if (auto msg = rx_queue_.pop(timeout)) {
      return T::deserialize(msg->data);
    }
    return std::nullopt;
  }

  std::optional<T> get_latest() {
    std::optional<T> latest;
    while (auto msg = receive()) {
      latest = msg;
    }
    if (latest) {
      error_count_ = 0;
    } else {
      error_count_++;
    }
    return latest;
  }

  bool error_occurred() const { return error_count_ > ERROR_COUNT_THRESHOLD; }

private:
  static constexpr uint32_t ERROR_COUNT_THRESHOLD = 10;

  halx::peripheral::CanBase &can_;
  halx::core::RingBuffer<halx::peripheral::CanMessage> rx_queue_{64};
  size_t filter_index_;
  uint32_t error_count_ = 0;
};

} // namespace catchrobo2025::can