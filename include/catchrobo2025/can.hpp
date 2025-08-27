#pragma once

#include "catchrobo2025/project_name.hpp"

#include "can/publisher.hpp"
#include "can/subscription.hpp"

#include "msg/end_effector_mode_telemetry.hpp"
#include "msg/end_effector_order.hpp"
#include "msg/localization.hpp"
#include "msg/main_arm_mode_telemetry.hpp"
#include "msg/mode_order.hpp"
#include "msg/pos_inst.hpp"

namespace catchrobo2025::can {

#ifdef CATCHROBO2025_MAIN
using ModeOrderPub = Publisher<0x0f0, msg::ModeOrder>;
using EndEffectorOrderPub = Publisher<0x11, msg::EndEffectorOrder>;
using PosInstPub = Publisher<0x021, msg::PosInst>;

using EndEffectorModeTelemetrySub = Subscription<0x10, msg::EndEffectorModeTelemetry>;
using MainArmModeTelemetrySub = Subscription<0x11, msg::MainArmModeTelemetry>;
using LocalizationSub = Subscription<0x21, msg::Localization>;
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
