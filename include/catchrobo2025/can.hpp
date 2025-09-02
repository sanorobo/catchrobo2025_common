#pragma once

#include "catchrobo2025/project_name.hpp"

#include "can/publisher.hpp"
#include "can/subscription.hpp"

#include "msg/end_effector_order.hpp"
#include "msg/primitive.hpp"
#include "msg/vector2.hpp"

namespace catchrobo2025::can {

#ifdef CATCHROBO2025_MAIN
// ブロードキャスト
using ModeOrderPub = Publisher<0xF1, msg::Primitive<uint8_t>>;

// end effector
using EndEffectorOrderPub = Publisher<0x11, msg::EndEffectorOrder>;

using EndEffectorModeTelemetrySub = Subscription<0x1F, msg::Primitive<uint8_t>>;

// arm
using ArmModeOrderPub = Publisher<0x21, msg::Primitive<uint8_t>>;
using ArmPosOrderPub = Publisher<0x22, msg::Vector2>;

using ArmTelemetrySub = Subscription<0x2F, msg::Primitive<uint8_t>>;
using ArmLocalizationSub = Subscription<0x2E, msg::Vector2>;

// stocker
using StockerOrderPub = Publisher<0x51, msg::Primitive<uint8_t>>;

using StockerTelemetrySub = Subscription<0x5F, msg::Primitive<uint8_t>>;
#endif

#ifdef CATCHROBO2025_ARM
using ArmTelemetryPub = Publisher<0x2F, msg::Primitive<uint8_t>>;
using ArmLocalizationPub = Publisher<0x2E, msg::Vector2>;

using ModeOrderSub = Subscription<0xF1, msg::Primitive<uint8_t>>;
using ArmModeOrderSub = Subscription<0x21, msg::Primitive<uint8_t>>;
using ArmPosOrderSub =  Subscription<0x22, msg::Vector2>;
#endif

#ifdef CATCHROBO2025_END_EFFECTOR
using TelemetryPub = Publisher<0x1F, msg::Primitive<uint8_t>>;
using ModeOrderSub = Subscription<0xF1, msg::Primitive<uint8_t>>;
using OrderSub = Subscription<0x11, msg::EndEffectorOrder>;
#endif

#ifdef CATCHROBO2025_HAND
#endif

#ifdef CATCHROBO2025_STOCKER
using TelemetryPub = Publisher<0x5f, msg::Primitive<uint8_t>>;
using OrderSub = Subscription<0x51, msg::Primitive<uint8_t>>;
#endif

enum class StockerOrder : uint8_t { HOMING = 10, STOCK_1 = 11, STOCK_2 = 12, STOCK_3 = 13, STOCK_4 = 14, STOCK_5 = 15, STOCK_6 = 16 };
enum class StockerTelemetry : uint8_t { READY = 10, RUNNING = 11 };
} // namespace catchrobo2025::can
