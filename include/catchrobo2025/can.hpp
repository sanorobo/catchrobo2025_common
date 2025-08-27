#pragma once

#include "catchrobo2025/project_name.hpp"

#include "can/publisher.hpp"
#include "can/subscription.hpp"

#include "msg/end_effector_order.hpp"
#include "msg/primitive.hpp"
#include "msg/vector2.hpp"

namespace catchrobo2025::can {

#ifdef CATCHROBO2025_MAIN
using ModeOrderPub = Publisher<0x0f0, msg::Primitive<uint8_t>>;
using EndEffectorOrderPub = Publisher<0x11, msg::EndEffectorOrder>;
using PosInstPub = Publisher<0x021, msg::Vector2>;

using EndEffectorModeTelemetrySub = Subscription<0x10, msg::Primitive<uint8_t>>;
using MainArmModeTelemetrySub = Subscription<0x11, msg::Primitive<uint8_t>>;
using LocalizationSub = Subscription<0x21, msg::Vector2>;
#endif

#ifdef CATCHROBO2025_ARM
#endif

#ifdef CATCHROBO2025_END_EFFECTOR
#endif

#ifdef CATCHROBO2025_HAND
#endif

#ifdef CATCHROBO2025_STOCKER
#endif

} // namespace catchrobo2025::can
