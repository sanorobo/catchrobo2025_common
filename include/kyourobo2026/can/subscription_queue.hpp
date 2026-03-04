#pragma once

#include <atomic>
#include <cstddef>
#include <cstdint>
#include <exception>
#include <optional>

#include <halx/core.hpp>
#include <halx/peripheral/can.hpp>
#include <halx/rtos.hpp>

namespace kyourobo2026::can {

template <uint32_t Id, class T> class SubscriptionQueue {
public:
  SubscriptionQueue(halx::peripheral::CanBase &can, size_t capacity = 10) : can_{can}, rx_queue_(capacity) {
    auto filter_index = can_.attach_rx_filter(
        {Id, (1 << 11) - 1, false},
        [](void *context, const halx::peripheral::CanMessage &msg) {
          auto *subscription = static_cast<SubscriptionQueue *>(context);
          subscription->rx_queue_.push(msg);
        },
        this);
    if (!filter_index) {
      std::terminate();
    }
    filter_index_ = *filter_index;
  }

  ~SubscriptionQueue() { can_.detach_rx_filter(filter_index_); }

  std::optional<T> pop() {
    if (auto msg = rx_queue_.pop()) {
      return T::deserialize(msg->data);
    }
    return std::nullopt;
  }

private:
  halx::peripheral::CanBase &can_;
  halx::rtos::Queue<halx::peripheral::CanMessage> rx_queue_;
  size_t filter_index_;
};

} // namespace kyourobo2026::can