#pragma once

#include <concepts>
#include <optional>

#include <halx/peripheral/can.hpp>

namespace catchrobo2025::messages {

using halx::peripheral::CanMessage;

template <class T> std::optional<T> from_can_message(const CanMessage &msg);

} // namespace catchrobo2025::messages
