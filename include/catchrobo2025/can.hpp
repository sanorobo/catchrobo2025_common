#pragma once

#include "catchrobo2025/project_name.hpp"

#include "can/publisher.hpp"
#include "can/subscription.hpp"

#include "msg/end_effector_order.hpp"
#include "msg/primitive.hpp"
#include "msg/vector2.hpp"

namespace catchrobo2025::can {

#ifdef CATCHROBO2025_MAIN
using ModeOrderPub = Publisher<0xF0, msg::Primitive<uint8_t>>;
using EndEffectorOrderPub = Publisher<0x11, msg::EndEffectorOrder>;
using PosInstPub = Publisher<0x21, msg::Vector2>;
using ArmModeOrderPub = Publisher<0x22, msg::Primitive<uint8_t>>;
using StockerOrderPub = Publisher<0x50, msg::Primitive<uint8_t>>;

using EndEffectorModeTelemetrySub = Subscription<0x100, msg::Primitive<uint8_t>>;
using MainArmModeTelemetrySub = Subscription<0x200, msg::Primitive<uint8_t>>;
using LocalizationSub = Subscription<0x201, msg::Vector2>;
using StockerTelemetrySub = Subscription<0x5F, msg::Primitive<uint8_t>>;
#endif

#ifdef CATCHROBO2025_ARM
#endif

#ifdef CATCHROBO2025_END_EFFECTOR
#endif

#ifdef CATCHROBO2025_HAND
#endif

#ifdef CATCHROBO2025_STOCKER
using TelemetryPub = Publisher<0x5f, msg::Primitive<uint8_t>>;
using OrderSub = Subscription<0x50, msg::Primitive<uint8_t>>;
#endif

} // namespace catchrobo2025::can
