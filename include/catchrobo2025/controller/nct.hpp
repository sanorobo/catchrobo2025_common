#pragma once

#include <algorithm>
#include <array>
#include <cmath>
#include <iterator>

namespace tutmath {

template <std::size_t PN, std::size_t NN> class NCTController {
private:
  const std::array<float, PN> &_p_error;
  const std::array<float, PN> &_p_vel;
  const std::array<float, NN> &_n_error;
  const std::array<float, NN> &_n_vel;

  template <std::size_t N> size_t get_closest_iterator(float error, const std::array<float, N> &error_arr) {
    auto it = std::lower_bound(error_arr.begin(), error_arr.end(), error);
    size_t i = std::distance(error_arr.begin(), it);
    if (i > 0) {
      if (std::abs(error_arr.at(i - 1) - error) < (error_arr.at(i) - error)) {
        return i - 1;
      }
    }
    return i;
  }

public:
  NCTController(const std::array<float, PN> &p_error, const std::array<float, PN> &p_vel, const std::array<float, NN> &n_error, const std::array<float, NN> &n_vel)
      : _p_error(p_error), _p_vel(p_vel), _n_error(n_error), _n_vel(n_vel) {}

  float solve(float error) {
    if (error > 0) {
      if (error <= _p_error.at(_p_error.size() - 1)) {
        return _p_vel.at(get_closest_iterator<PN>(error, _p_error));
      } else {
        return _p_vel.at(_p_error.size() - 1);
      }
    } else {
      if (error >= _n_error.at(0)) {
        return _n_vel.at(get_closest_iterator<NN>(error, _n_error));
      } else {
        return _n_vel.at(0);
      }
    }
  }
};

} // namespace tutmath