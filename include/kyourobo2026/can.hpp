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
using OpenCloseSub = Publisher<0x11, catchrobo2025::msg::Primitive<uint8_t>>;
using UpDownSub = Publisher<0x12, catchrobo2025::msg::Primitive<uint8_t>>;
using TurretYawSub = Publisher<0x13, catchrobo2025::msg::Primitive<uint8_t>>;

using Spiral1Sub = Publisher<0x14, catchrobo2025::msg::Primitive<uint8_t>>;
using Spiral2Sub = Publisher<0x15, catchrobo2025::msg::Primitive<uint8_t>>;
using Spiral3Sub = Publisher<0x16, catchrobo2025::msg::Primitive<uint8_t>>;

using Entire = Publisher<0x17, catchrobo2025::msg::Primitive<uint8_t>>;

using Pub = Subscription<0x20, catchrobo2025::msg::Primitive<uint16_t>>;

using FeetechPositionPub = Publisher<0x31, msg::ServoPosition>;
using FeetechPositionSub = Subscription<0x32, msg::ServoPosition>;
using PwmServoPositionPub = Publisher<0x33, msg::ServoPosition>;
#endif

#ifdef KYOUROBO2026_ATAMA
using OpenCloseSub = Subscription<0x11, catchrobo2025::msg::Primitive<uint8_t>>;
using UpDownSub = Subscription<0x12, catchrobo2025::msg::Primitive<uint8_t>>;
using TurretYawSub = Subscription<0x13, catchrobo2025::msg::Primitive<uint8_t>>;

using Spiral1Sub = Subscription<0x14, catchrobo2025::msg::Primitive<uint8_t>>;
using Spiral2Sub = Subscription<0x15, catchrobo2025::msg::Primitive<uint8_t>>;
using Spiral3Sub = Subscription<0x16, catchrobo2025::msg::Primitive<uint8_t>>;

using Entire = Subscription<0x17, catchrobo2025::msg::Primitive<uint8_t>>;

using Pub = Publisher<0x20, catchrobo2025::msg::Primitive<uint16_t>>;
#endif

#ifdef KYOUROBO2026_SERVO
using FeetechPositionSub = Subscription<0x31, msg::ServoPosition>;
using FeetechPositionPub = Publisher<0x32, msg::ServoPosition>;
using PwmServoPositionSub = Subscription<0x33, msg::ServoPosition>;
#endif

} // namespace kyourobo2026::can
