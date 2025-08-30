#pragma once

#include <atomic>
#include <cstddef>
#include <cstdint>
#include <exception>
#include <optional>

#include <halx/core.hpp>
#include <halx/peripheral/can.hpp>
#include <halx/rtos.hpp>

namespace catchrobo2025::can {

template <uint32_t Id, class T> class Subscription {
public:
  Subscription(halx::peripheral::CanBase &can, uint32_t timeout = 1000) : can_{can}, timeout_{timeout} {
    auto filter_index = can_.attach_rx_filter(
        {Id, Id, false},
        [](void *context, const halx::peripheral::CanMessage &msg) {
          auto *subscription = static_cast<Subscription *>(context);
          subscription->rx_mailbox_.push(msg);
          subscription->last_received_.store(halx::core::get_tick(), std::memory_order_release);
        },
        this);
    if (!filter_index) {
      std::terminate();
    }
    filter_index_ = *filter_index;
  }

  ~Subscription() { can_.detach_rx_filter(filter_index_); }

  std::optional<T> peek() {
    if (static_cast<uint32_t>(halx::core::get_tick() - last_received_.load(std::memory_order_acquire)) > timeout_) {
      return std::nullopt; // タイムアウト起きてる(デフォルト: 1秒)
    }
    if (auto msg = rx_mailbox_.peek()) {
      return T::deserialize(msg->data);
    }
    return std::nullopt;
  }

private:
  halx::peripheral::CanBase &can_;
  halx::rtos::Mailbox<halx::peripheral::CanMessage> rx_mailbox_;
  size_t filter_index_;
  uint32_t timeout_;
  std::atomic<uint32_t> last_received_{0};
};

} // namespace catchrobo2025::can