#include "./formal-power-series.hpp"

template <typename mint>
FormalPowerSeries<mint> Pi(vector<FormalPowerSeries<mint>> v) {
  using fps = FormalPowerSeries<mint>;
  sort(begin(v), end(v), [](fps &a, fps &b) { return a.size() < b.size(); });
  vector<fps> w;
  w.reserve(sz(v) / 2 + 1);
  while ((int)v.size() > 1) {
    for (int i = 0; i < (int)v.size(); i += 2) {
      if (i + 1 == (int)v.size()) {
        w.emplace_back(v.back());
      } else {
        w.emplace_back(v[i] * v[i + 1]);
      }
    }
    swap(v, w);
    w.clear();
  }
  return v[0];
}
