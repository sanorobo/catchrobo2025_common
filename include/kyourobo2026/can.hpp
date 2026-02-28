#pragma once

#include "catchrobo2025/project_name.hpp"

#include "catchrobo2025/can/publisher.hpp"
#include "catchrobo2025/can/subscription.hpp"

#include "catchrobo2025/msg/enum_set.hpp"
#include "catchrobo2025/msg/primitive.hpp"

#include "msg/open_close_state.hpp"
#include "msg/servo_position.hpp"

namespace kyourobo2026::can {

using catchrobo2025::can::Publisher;
using catchrobo2025::can::Subscription;

#ifdef KYOUROBO2026_ASHI
using OpenClosePub = Publisher<0x11, catchrobo2025::msg::Primitive<msg::OpenCloseState>>;
using UpDownPub = Publisher<0x12, catchrobo2025::msg::Primitive<float>>;
using TurretYawPub = Publisher<0x13, catchrobo2025::msg::Primitive<float>>;

using Spiral1Pub = Publisher<0x14, catchrobo2025::msg::Primitive<float>>;
using Spiral2Pub = Publisher<0x15, catchrobo2025::msg::Primitive<float>>;
using Spiral3Pub = Publisher<0x16, catchrobo2025::msg::Primitive<float>>;

using FeetechPositionPub = Publisher<0x31, msg::ServoPosition>;
using FeetechPositionSub = Subscription<0x32, msg::ServoPosition>;
using PwmServoPositionPub = Publisher<0x33, msg::ServoPosition>;
#endif

#ifdef KYOUROBO2026_ATAMA
using OpenCloseSub = Subscription<0x11, catchrobo2025::msg::Primitive<msg::OpenCloseState>>;
using UpDownSub = Subscription<0x12, catchrobo2025::msg::Primitive<float>>;
using TurretYawSub = Subscription<0x13, catchrobo2025::msg::Primitive<float>>;

using Spiral1Sub = Subscription<0x14, catchrobo2025::msg::Primitive<float>>;
using Spiral2Sub = Subscription<0x15, catchrobo2025::msg::Primitive<float>>;
using Spiral3Sub = Subscription<0x16, catchrobo2025::msg::Primitive<float>>;
#endif

#ifdef KYOUROBO2026_SERVO
using FeetechPositionSub = Subscription<0x31, msg::ServoPosition>;
using FeetechPositionPub = Publisher<0x32, msg::ServoPosition>;
using PwmServoPositionSub = Subscription<0x33, msg::ServoPosition>;
#endif

} // namespace kyourobo2026::can
