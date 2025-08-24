#pragma once

#include <algorithm>
#include <cmath>
#include <iterator>
#include <vector>

namespace tutmath {

struct nct_t {
  std::vector<float> p_error;
  std::vector<float> p_vel;
  std::vector<float> n_error;
  std::vector<float> n_vel;
};

class NCTController {
private:
  nct_t _nct;

  size_t get_closest_iterator(float error, const std::vector<float> &error_vec) {
    auto it = std::lower_bound(error_vec.begin(), error_vec.end(), error);
    size_t i = std::distance(error_vec.begin(), it);
    if (i > 0) {
      if (std::abs(error_vec.at(i - 1) - error) < (error_vec.at(i) - error)) {
        return i - 1;
      }
    }
    return i;
  }

public:
  void init(const nct_t &nct) { _nct = nct; }

  float solve(float error) {
    if (error > 0) {
      if (error <= _nct.p_error.at(_nct.p_error.size() - 1)) {
        return _nct.p_vel.at(get_closest_iterator(error, _nct.p_error));
      } else {
        return _nct.p_vel.at(_nct.p_error.size() - 1);
      }
    } else {
      if (error >= _nct.n_error.at(0)) {
        return _nct.n_vel.at(get_closest_iterator(error, _nct.n_error));
      } else {
        return _nct.n_vel.at(0);
      }
    }
  }
};

} // namespace tutmath