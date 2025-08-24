#pragma once

#include <algorithm>
#include <optional>

namespace tutmath {

struct pid_params_t {
  float delta = 1.0;
  float kp = 0.0;
  float ki = 0.0;
  float kd = 0.0;
  float klpf = 0.0;
  std::optional<float> output_upper_limit = std::nullopt;
  std::optional<float> integral_upper_limit = std::nullopt;
};

class PidController {
private:
  pid_params_t _pid_params;
  float _diff[2] = {0, 0};
  float _indx = 0;

public:
  void init(const pid_params_t &params) { _pid_params = params; }

  void reset() {
    _indx = 0;
    _diff[1] = 0;
  }

  float solve(float ERROR, bool IS_VALID_INTEGRAL = true) {
    _diff[0] = _diff[1];

    if (_pid_params.klpf) {
      _diff[1] += _pid_params.klpf * (ERROR - _diff[0]);
    } else {
      _diff[1] = ERROR;
    }

    if (IS_VALID_INTEGRAL) {
      _indx += _diff[1] * _pid_params.delta;
    }

    // 積分項クリップ
    if (_pid_params.integral_upper_limit) {
      _indx = std::clamp(_indx, -*_pid_params.integral_upper_limit, *_pid_params.integral_upper_limit);
    }

    float output = _pid_params.kp * _diff[1] + _pid_params.ki * _indx + _pid_params.kd * (_diff[1] - _diff[0]) / _pid_params.delta;

    // 出力クリップ
    if (_pid_params.output_upper_limit) {
      output = std::clamp(output, -*_pid_params.output_upper_limit, *_pid_params.output_upper_limit);
    }

    return output;
  }
};

} // namespace tutmath