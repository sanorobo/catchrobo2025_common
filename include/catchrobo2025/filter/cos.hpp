#pragma once

#include <cmath>
#include <numbers>

namespace tutmath {

class CosFilter {
private:
  float _target_val;
  float _target_tim_diff;
  float _start_tim;

public:
  void init(float val) { _target_tim_diff = val; }

  void reset(float val, float tim) {
    _target_val = val;
    _start_tim = tim;
  }

  float solve(float tim) {
    if (tim - _start_tim < _target_tim_diff) {
      return _target_val * (1.0 - 0.5 * (std::cos(std::numbers::pi * (tim - _start_tim) / _target_tim_diff) + 1.0));
    } else {
      return _target_val;
    }
  }
};

} // namespace tutmath