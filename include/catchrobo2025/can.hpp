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
using ArmModeOrderPub = Publisher<0x20, msg::Primitive<uint8_t>>;
using ArmPosOrderPub = Publisher<0x21, msg::Vector2>;
using StockerOrderPub = Publisher<0x50, msg::Primitive<uint8_t>>;

using EndEffectorModeTelemetrySub = Subscription<0x100, msg::Primitive<uint8_t>>;
using ArmTelemetrySub = Subscription<0x2F, msg::Primitive<uint8_t>>;
using ArmLocalizationSub = Subscription<0x2E, msg::Vector2>;
using StockerTelemetrySub = Subscription<0x5F, msg::Primitive<uint8_t>>;
#endif

#ifdef CATCHROBO2025_ARM
using ArmTelemetryPub = Publisher<0x2F, msg::Primitive<uint8_t>>;
using ArmLocalizationPub = Publisher<0x2E, msg::Vector2>;

using ModeOrderSub = Subscription<0xF0, msg::Primitive<uint8_t>>;
using ArmModeOrderSub = Subscription<0x20, msg::Primitive<uint8_t>>;
using ArmPosOrderSub =  Subscription<0x21, msg::Vector2>;
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
