#pragma once

#include <cmath>

#include "constant.hpp"

namespace tutmath {

// 角度[rad]を0<=θ<2πの範囲に修正
inline float radian(float ang) {
  while (ang >= 2 * pi) {
    ang -= 2 * pi;
  }
  while (ang < 0) {
    ang += 2 * pi;
  }
  return ang;
}

// 角度[°]を0<=θ<360の範囲に修正
inline float degree(float ang) {
  while (ang >= 360) {
    ang -= 360;
  }
  while (ang < 0) {
    ang += 360;
  }
  return ang;
}

// 角度[rad]の差を計算
inline float dradian(float target_ang, float state_ang) {
  target_ang = radian(target_ang);
  state_ang = radian(state_ang);
  if (std::abs((target_ang + 2 * pi) - state_ang) < std::abs(target_ang - state_ang)) {
    target_ang += 2 * pi;
  }
  if (std::abs((target_ang - 2 * pi) - state_ang) < std::abs(target_ang - state_ang)) {
    target_ang -= 2 * pi;
  }
  return state_ang - target_ang;
}

// 角度[°]の差を計算
inline float ddegree(float target_ang, float state_ang) {
  target_ang = degree(target_ang);
  state_ang = degree(state_ang);
  if (std::abs((target_ang + 360) - state_ang) < std::abs(target_ang - state_ang)) {
    target_ang += 360;
  }
  if (std::abs((target_ang - 360) - state_ang) < std::abs(target_ang - state_ang)) {
    target_ang -= 360;
  }
  return state_ang - target_ang;
}

} // namespace tutmath