#pragma once

#include <cmath>
#include <concepts>
#include <numbers>

namespace tutmath {

template <std::floating_point T> constexpr T from_degrees(T degrees) { return degrees * std::numbers::pi_v<T> / T{180.0}; }

template <std::floating_point T> constexpr T to_degrees(T radians) { return radians * T{180.0} / std::numbers::pi_v<T>; }

template <std::floating_point T> constexpr T normalize_angle_positive(T angle) {
  T result = std::fmod(angle, T{2.0} * std::numbers::pi_v<T>);
  if (result < T{0.0}) {
    return result + T{2.0} * std::numbers::pi_v<T>;
  }
  return result;
}

template <std::floating_point T> constexpr T normalize_angle(T angle) {
  T result = std::fmod(angle + std::numbers::pi_v<T>, T{2.0} * std::numbers::pi_v<T>);
  if (result <= T{0.0}) {
    return result + std::numbers::pi_v<T>;
  }
  return result - std::numbers::pi_v<T>;
}

// 角度[rad]を0<=θ<2πの範囲に修正
inline float radian(float ang) {
  while (ang >= 2 * std::numbers::pi) {
    ang -= 2 * std::numbers::pi;
  }
  while (ang < 0) {
    ang += 2 * std::numbers::pi;
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
  if (std::abs((target_ang + 2 * std::numbers::pi) - state_ang) < std::abs(target_ang - state_ang)) {
    target_ang += 2 * std::numbers::pi;
  }
  if (std::abs((target_ang - 2 * std::numbers::pi) - state_ang) < std::abs(target_ang - state_ang)) {
    target_ang -= 2 * std::numbers::pi;
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