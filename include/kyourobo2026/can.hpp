#pragma once

#include "catchrobo2025/project_name.hpp"

#include "catchrobo2025/can/publisher.hpp"
#include "catchrobo2025/can/subscription.hpp"

#include "catchrobo2025/msg/enum_set.hpp"
#include "catchrobo2025/msg/primitive.hpp"

#include "can/subscription_queue.hpp"
#include "msg/open_close_state.hpp"
#include "msg/servo_position.hpp"

namespace kyourobo2026::can {

using catchrobo2025::can::Publisher;
using catchrobo2025::can::Subscription;

#ifdef KYOUROBO2026_ASHI
using OpenClosePub = Publisher<0x11, catchrobo2025::msg::Primitive<uint8_t>>;
using UpDownPub = Publisher<0x12, catchrobo2025::msg::Primitive<uint8_t>>;
using TurretYawPub = Publisher<0x13, catchrobo2025::msg::Primitive<uint8_t>>;

using Spiral1Pub = Publisher<0x14, catchrobo2025::msg::Primitive<uint8_t>>;
using Spiral2Pub = Publisher<0x15, catchrobo2025::msg::Primitive<uint8_t>>;
using Spiral3Pub = Publisher<0x16, catchrobo2025::msg::Primitive<uint8_t>>;

using Entire = Publisher<0x17, catchrobo2025::msg::Primitive<uint8_t>>;

using Sub = Subscription<0x20, catchrobo2025::msg::Primitive<uint16_t>>;

using FeetechPositionPub = Publisher<0x31, msg::ServoPosition>;
using FeetechPositionSub = Subscription<0x32, msg::ServoPosition>;
using PwmServoPositionPub = Publisher<0x33, msg::ServoPosition>;
#endif

#ifdef KYOUROBO2026_ATAMA
using OpenCloseSub = SubscriptionQueue<0x11, catchrobo2025::msg::Primitive<uint8_t>>;
using UpDownSub = SubscriptionQueue<0x12, catchrobo2025::msg::Primitive<uint8_t>>;
using TurretYawSub = SubscriptionQueue<0x13, catchrobo2025::msg::Primitive<uint8_t>>;

using Spiral1Sub = SubscriptionQueue<0x14, catchrobo2025::msg::Primitive<uint8_t>>;
using Spiral2Sub = SubscriptionQueue<0x15, catchrobo2025::msg::Primitive<uint8_t>>;
using Spiral3Sub = SubscriptionQueue<0x16, catchrobo2025::msg::Primitive<uint8_t>>;

using Entire = SubscriptionQueue<0x17, catchrobo2025::msg::Primitive<uint8_t>>;

using Pub = Publisher<0x20, catchrobo2025::msg::Primitive<uint16_t>>;
#endif

#ifdef KYOUROBO2026_SERVO
using FeetechPositionSub = Subscription<0x31, msg::ServoPosition>;
using FeetechPositionPub = Publisher<0x32, msg::ServoPosition>;
using PwmServoPositionSub = Subscription<0x33, msg::ServoPosition>;
#endif

// 機構動作指令の定数定義
enum OPEN_CLOSE_MECHA {
  OPEN_CLOSE_IDLE = 0,
  OPEN_CLOSE_INIT = 1,
  OPEN = 2,
  CLOSE = 3,
  OPEN_CLOSE_NUM,
};

enum UP_DOWN_MECHA {
  UP_DOWN_IDLE = 0,
  UP_DOWN_INIT = 1,
  HEIGHT_RELOAD = 2,
  HEIGHT_THROW = 3,
  HEIGHT_COLLECT_READY = 4,
  HEIGHT_COLLECT_ACTION = 5,
  UP_DOWN_NUM,
};

enum TURRET_YAW_MECHA { TURRET_YAW_IDLE = 0, TURRET_YAW_INIT = 1, TURRET_YAW_MAX = 2, TURRET_YAW_NUM };

enum SPIRAL_MECHA {
  SPIRAL_IDLE = 0,
  SPIRAL_INIT = 1,
  CW = 2,
  CCW = 3,
  COLLECT = 4,
  LOAD = 5,
  SPIRAL_NUM,
};

} // namespace kyourobo2026::can
