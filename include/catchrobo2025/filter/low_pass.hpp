#pragma once

namespace tutmath {

class LowPassFilter {
private:
  float _klpf;
  float _val = 0;

public:
  void init(float klpf) { _klpf = klpf; }

  void reset(float val) { _val = val; }

  float solve(float val) {
    _val += _klpf * (val - _val);

    return _val;
  }
};

} // namespace tutmath